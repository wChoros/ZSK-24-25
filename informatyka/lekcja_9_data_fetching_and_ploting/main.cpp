#include <iostream>
#include <string>
#include <vector>
#include <cstdio>      // for FILE*, fgets, etc.
#include <algorithm>   // for std::replace
#include <OpenXLSX.hpp>

// A simple struct to store currency data
struct CurrencyRate {
    std::string currencyName;
    std::string currencyCode;
    double averageRate;
};

//------------------------------------------------------------------------------
// 1) Fetch XML via a system call to 'curl' (HTTPS request without extra libs).
//    This function returns the entire XML response as a std::string.
//------------------------------------------------------------------------------
std::string fetchXML(const std::string& url) {
    std::string result;

    // Build the curl command
    std::string cmd = "curl -s " + url;

    // Open a pipe from which we read the command's output
    // NOTE: popen is POSIX-specific; on Windows you may need _popen
    FILE* pipe = popen(cmd.c_str(), "r");
    if (!pipe) {
        std::cerr << "Could not open pipe for curl command." << std::endl;
        return "";
    }

    const int BUFFER_SIZE = 8192;
    char buffer[BUFFER_SIZE];

    // Read until EOF
    while (!feof(pipe)) {
        if (fgets(buffer, BUFFER_SIZE, pipe) != nullptr) {
            result += buffer;
        }
    }

    // Close the pipe
    pclose(pipe);

    return result;
}

//------------------------------------------------------------------------------
// 2) Naive extraction of <tag>value</tag> from a block of XML.
//    This is purely string-based and not robust for complicated XML.
//------------------------------------------------------------------------------
std::string getTagValue(const std::string& block,
                        const std::string& tagName)
{
    // e.g. tagName = "kod_waluty"
    // we look for <kod_waluty>...</kod_waluty>
    std::string openTag  = "<" + tagName + ">";
    std::string closeTag = "</" + tagName + ">";

    size_t start = block.find(openTag);
    if (start == std::string::npos) {
        return "";
    }
    start += openTag.size(); // move past <tagName>

    size_t end = block.find(closeTag, start);
    if (end == std::string::npos) {
        return "";
    }

    return block.substr(start, end - start);
}

//------------------------------------------------------------------------------
// 3) Parse the XML string to extract all <pozycja> blocks and read relevant fields
//------------------------------------------------------------------------------
std::vector<CurrencyRate> parseXML(const std::string& xmlData)
{
    std::vector<CurrencyRate> result;

    // We'll look for <pozycja> ... </pozycja>
    // and inside each one, get <nazwa_waluty>, <kod_waluty>, <kurs_sredni>.

    // Start scanning for <pozycja>
    const std::string startTag = "<pozycja>";
    const std::string endTag   = "</pozycja>";

    size_t startPos = 0;
    while (true) {
        size_t posBegin = xmlData.find(startTag, startPos);
        if (posBegin == std::string::npos) {
            break; // no more <pozycja> found
        }
        size_t posEnd = xmlData.find(endTag, posBegin);
        if (posEnd == std::string::npos) {
            break; // malformed or incomplete
        }
        // Extract this entire <pozycja>...</pozycja> block
        size_t blockLen = (posEnd + endTag.size()) - posBegin;
        std::string block = xmlData.substr(posBegin, blockLen);

        // Attempt to extract fields
        CurrencyRate cr;
        cr.currencyName  = getTagValue(block, "nazwa_waluty");
        cr.currencyCode  = getTagValue(block, "kod_waluty");

        // "kurs_sredni" often uses commas, e.g. "4,0215"
        std::string rawRate = getTagValue(block, "kurs_sredni");
        if (!rawRate.empty()) {
            // replace ',' with '.'
            std::replace(rawRate.begin(), rawRate.end(), ',', '.');
            try {
                cr.averageRate = std::stod(rawRate);
            }
            catch (...) {
                cr.averageRate = 0.0;
            }
        }

        // Add to results
        result.push_back(cr);

        // Update startPos to search for the next block
        startPos = posEnd + endTag.size();
    }

    return result;
}

//------------------------------------------------------------------------------
// 4) Write the currency data to an Excel file using OpenXLSX.
//
//    NOTE: Creating a brand-new chart in Excel from scratch using OpenXLSX
//    requires manual XML manipulation (OpenXLSX doesn't have a direct chart API).
//    The simpler approach is to open a *template* workbook that already has
//    a chart referencing cells A2:B20, for example. We just overwrite those
//    cells with new data, then when opened in Excel, the chart updates.
//
//------------------------------------------------------------------------------
void writeToExcel(const std::vector<CurrencyRate>& rates,
                  const std::string& templateFile,
                  const std::string& outputFile)
{
    try {
        OpenXLSX::XLDocument doc;
        doc.open(templateFile);

        auto wks = doc.workbook().worksheet("NBP_ExchangeRates");  // or adapt if your sheet is named differently

        // Optionally write headers (if your template doesn't have them):
        // wks.cell("A1").value() = "Currency";
        // wks.cell("B1").value() = "Rate";

        // Start writing from row 2 downward
        int row = 2;
        for (const auto& cr : rates) {
            // A: currency code, B: averageRate
            std::string cellA = "A" + std::to_string(row);
            std::string cellB = "B" + std::to_string(row);

            wks.cell(cellA).value() = cr.currencyCode;
            wks.cell(cellB).value() = cr.averageRate;

            ++row;
        }

        doc.saveAs(outputFile);
        doc.close();

        std::cout << "Data successfully written to " << outputFile << std::endl;
        std::cout << "Open '" << outputFile << "' in Excel to see the updated chart.\n";
    }
    catch (std::exception &e) {
        std::cerr << "Failed to write Excel: " << e.what() << std::endl;
    }
}

//------------------------------------------------------------------------------
// main
//------------------------------------------------------------------------------
int main()
{
    // The NBP URL
    const std::string url = "https://static.nbp.pl/dane/kursy/xml/a029z250212.xml";

    // 1) Fetch XML (via a child process calling 'curl')
    std::cout << "Fetching XML from " << url << "...\n";
    std::string xmlData = fetchXML(url);
    if (xmlData.empty()) {
        std::cerr << "No XML data fetched.\n";
        return 1;
    }

    // 2) Parse the XML (naïve string approach)
    auto rates = parseXML(xmlData);
    std::cout << "Parsed " << rates.size() << " currency entries.\n";

    // For debugging:
    for (auto &r : rates) {
        std::cout << r.currencyCode << " -> " << r.averageRate << "\n";
    }

    // 3) Write to Excel (relying on a template that already has a chart)
    std::string templateFile = "../../template_with_chart.xlsx";     // must exist
    std::string outputFile   = "../../NBP_ExchangeRates_Output.xlsx";
    writeToExcel(rates, templateFile, outputFile);

    return 0;
}
