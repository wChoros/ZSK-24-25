#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <list>
#include <algorithm> // For std::swap

class Data {
private:
    std::list<int> array;

public:
    // Constructor initializes the list
    Data() {
        srand(static_cast<unsigned int>(time(0)));
        for (int i = 0; i < 200; i++) {
            int num = rand() % 100;
            array.push_back(num);
        }
    }

    void BubbleSort() {
        for (auto it1 = array.begin(); it1 != array.end(); ++it1) {
            auto it2 = it1;
            ++it2;
            for (; it2 != array.end(); ++it2) {
                if (*it1 > *it2) {
                    std::swap(*it1, *it2);
                }
            }
        }
    }

    void WriteToFile(const std::string &filePath) {
        std::ofstream writer(filePath);
        if (writer.is_open()) {
            for (const auto &value: array) {
                writer << value << "\n";
            }
            writer.close();
            std::cout << "File created successfully..." << std::endl;
        } else {
            std::cout << "Unable to open file" << std::endl;
        }
    }

    void ReadFromFile(const std::string &filePath) {
        std::ifstream reader(filePath);
        if (reader.is_open()) {
            array.clear();
            std::string line;
            while (std::getline(reader, line)) {
                // Remove leading and trailing whitespace
                line.erase(0, line.find_first_not_of(" \t\r\n"));
                line.erase(line.find_last_not_of(" \t\r\n") + 1);
                if (!line.empty()) {
                    array.push_back(std::stoi(line));
                }
            }
            reader.close();
        } else {
            std::cout << "Unable to open file" << std::endl;
        }
    }

    void printArray() {
        for (const auto &value: array) {
            std::cout << value << "\n";
        }
    }
};

int main() {
    Data data; // List is initialized in the constructor

    // Sort and display the integer list
    data.BubbleSort();
    std::cout << "Sorted array:" << std::endl;
    data.printArray();

    std::string filePath = "../file.txt";
    std::cout << "File path: " << filePath << std::endl;

    // Write sorted list to file
    // data.WriteToFile(filePath);

    // Read data from file and store it into 'array'
    std::cout << "Reading file content and storing into array..." << std::endl;
    data.ReadFromFile(filePath);

    // Display the list after reading from the file
    std::cout << "Array after reading from file:" << std::endl;
    data.printArray();

    return 0;
}
