#include <iostream>
#include <list>
#include <vector>

using namespace std;

class Datetime {
public:
    int year, month, day, hour, minute, second;

    Datetime(const int year, const int month, const int day, const int hour, const int minute, const int second) {
        this->year = year;
        this->month = month;
        this->day = day;
        this->hour = hour;
        this->minute = minute;
        this->second = second;

        if (this->year < 0 || this->month < 1 || this->month > 12 || this->day < 1 || this->day > 31 || this->hour < 0 || this->hour > 23 || this->minute < 0 || this->minute > 59 || this->second < 0 || this->second > 59) {
            throw invalid_argument("Invalid date");
        }
    }

    void print() const {
        cout << year << "-" << month << "-" << day << " " << hour << ":" << minute << ":" << second << endl;
    }

    bool isDateSmallerThan(Datetime date) {
        Datetime date1 = *this;
        Datetime date2 = date;
        if (date1.year != date2.year) {
            return date1.year < date2.year;
        }
        if (date1.month != date2.month) {
            return date1.month < date2.month;
        }
        if (date1.day != date2.day) {
            return date1.day < date2.day;
        }
        if (date1.hour != date2.hour) {
            return date1.hour < date2.hour;
        }
        if (date1.minute != date2.minute) {
            return date1.minute < date2.minute;
        }
        return date1.second < date2.second;
    }
};

void sortDates(Datetime *dates, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (dates[j].isDateSmallerThan(dates[i])) {
                Datetime temp = dates[i];
                dates[i] = dates[j];
                dates[j] = temp;
            }
        }
    }
}

// overloading for list of dates
void sortDates(list<Datetime> &dates) {
    for (auto i = dates.begin(); i != dates.end(); ++i) {
        for (auto j = i; j != dates.end(); ++j) {
            if (j->isDateSmallerThan(*i)) {
                Datetime temp = *i;
                *i = *j;
                *j = temp;
            }
        }
    }
}

// overloading for vector of dates
void sortDates(vector<Datetime> &dates) {
    for (auto i = dates.begin(); i != dates.end(); ++i) {
        for (auto j = i; j != dates.end(); ++j) {
            if (j->isDateSmallerThan(*i)) {
                Datetime temp = *i;
                *i = *j;
                *j = temp;
            }
        }
    }
}

void printDates(Datetime *dates, int n) {
    for (int i = 0; i < n; i++) {
        dates[i].print();
    }
}

// overloading for list of dates
void printDates(list<Datetime> &dates) {
    for (auto &date: dates) {
        date.print();
    }
}

// overloading for vector of dates
void printDates(vector<Datetime> &dates) {
    for (auto &date: dates) {
        date.print();
    }
}

int main() {
    list<Datetime> dates = {
        Datetime(2023, 10, 1, 12, 0, 0),
        Datetime(2021, 12, 31, 23, 59, 57),
        Datetime(2021, 12, 31, 23, 59, 58),
        Datetime(2021, 12, 31, 23, 59, 59),
        Datetime(2024, 1, 20, 14, 45, 0),
        Datetime(2022, 5, 15, 8, 30, 0),
    };
    printDates(dates);
    cout << "-----------------" << endl;
    sortDates(dates);
    printDates(dates);
    cout << "-----------------" << endl;


    Datetime datesArray[] = {
        Datetime(2023, 10, 1, 12, 0, 0),
        Datetime(2021, 12, 31, 23, 59, 57),
        Datetime(2021, 12, 31, 23, 59, 58),
        Datetime(2021, 12, 31, 23, 59, 59),
        Datetime(2024, 1, 20, 14, 45, 0),
        Datetime(2022, 5, 15, 8, 30, 0),
    };
    printDates(datesArray, 6);
    cout << "-----------------" << endl;
    sortDates(datesArray, 6);
    printDates(datesArray, 6);
    cout << "-----------------" << endl;

    vector<Datetime> datesVector = {
        Datetime(2023, 10, 1, 12, 0, 0),
        Datetime(2021, 12, 31, 23, 59, 57),
        Datetime(2021, 12, 31, 23, 59, 58),
        Datetime(2021, 12, 31, 23, 59, 59),
        Datetime(2024, 1, 20, 14, 45, 0),
        Datetime(2022, 5, 15, 8, 30, 0),
    };
    printDates(datesVector);
    cout << "-----------------" << endl;
    sortDates(datesVector);
    printDates(datesVector);
    cout << "-----------------" << endl;
}
