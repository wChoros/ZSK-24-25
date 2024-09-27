#include <iostream>
#include <list>
#include <vector>

using namespace std;

class Sort {
public:
    static void BubbleSort(list<int> &list) {
        for (auto it1 = list.begin(); it1 != list.end(); ++it1) {
            for (auto it2 = list.begin(); it2 != prev(list.end(), distance(list.begin(), it1) + 1); ++it2) {
                auto next_it = next(it2);
                if (*it2 > *next_it) {
                    iter_swap(it2, next_it);
                }
            }
        }
    }

    static void SelectionSort(int array[], int size) {
        for (int i = 0; i < size; i++) {
            int minIndex = i;
            for (int j = i + 1; j < size; j++) {
                if (array[j] < array[minIndex]) {
                    minIndex = j;
                }
            }
            if (minIndex != i) {
                int temp = array[i];
                array[i] = array[minIndex];
                array[minIndex] = temp;
            }
        }
    }

    static void InsertionSort(vector<int> &array) {
        for (size_t i = 1; i < array.size(); i++) {
            int key = array[i];
            int j = i - 1;
            while (j >= 0 && array[j] > key) {
                array[j + 1] = array[j];
                j = j - 1;
            }
            array[j + 1] = key;
        }
    }
};

int main() {
    // create a list of random integers and sort it using Bubble Sort
    cout << "Bubble Sort" << endl;
    list<int> list;
    for (int i = 0; i < 100; i++) {
        list.push_back(rand() % 100);
    }
    Sort::BubbleSort(list);
    for (auto &i: list) {
        cout << i << " ";
    }
    cout << endl << endl;
    // create an array of random integers and sort it using Selection Sort
    cout << "Selection Sort" << endl;
    int array[100];
    for (int i = 0; i < 100; i++) {
        array[i] = rand() % 100;
    }
    Sort::SelectionSort(array, 100);
    for (int i = 0; i < 100; i++) {
        cout << array[i] << " ";
    }
    cout << endl << endl;
    // create a vector of random integers and sort it using Insertion Sort
    cout << "Insertion Sort" << endl;
    vector<int> vector;
    for (int i = 0; i < 100; i++) {
        vector.push_back(rand() % 100);
    }
    Sort::InsertionSort(vector);
    for (int i = 0; i < 100; i++) {
        cout << vector[i] << " ";
    }
    cout << endl << endl;
    return 0;
}
