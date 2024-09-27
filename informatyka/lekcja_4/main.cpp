#include <iostream>
#include <list>
#include <vector>

using namespace std;

class Sort {
    static bool isSorted(int array[], int size) {
        for (int i = 0; i < size - 1; i++) {
            if (array[i] > array[i + 1]) {
                return false;
            }
        }
        return true;
    }

    static void shuffle(int array[], int size) {
        for (int i = 0; i < size; i++) {
            int randomIndex = rand() % size;
            int temp = array[i];
            array[i] = array[randomIndex];
            array[randomIndex] = temp;
        }
    }

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

    static void BubbleSort(int array[], int size) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (array[j] > array[j + 1]) {
                    int temp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = temp;
                }
            }
        }
    }

    static void QuickSort(list<int> &main_list) {
        if (main_list.size() <= 1) {
            return;
        }
        int pivot = main_list.front();
        list<int> less;
        list<int> equal;
        list<int> greater;
        for (int &i: main_list) {
            if (i < pivot) {
                less.push_back(i);
            } else if (i == pivot) {
                equal.push_back(i);
            } else {
                greater.push_back(i);
            }
        }
        QuickSort(less);
        QuickSort(greater);
        main_list.clear();
        main_list.splice(main_list.end(), less);
        main_list.splice(main_list.end(), equal);
        main_list.splice(main_list.end(), greater);
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

    static void BogoSort(int array[], int size) {
        while (!isSorted(array, size)) {
            shuffle(array, size);
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
    cout << "Bubble Sort on list" << endl;
    list<int> list;
    for (int i = 0; i < 100; i++) {
        list.push_back(rand() % 100);
    }
    Sort::BubbleSort(list);
    for (auto &i: list) {
        cout << i << " ";
    }
    cout << endl << endl;

    // create an array of random integers and sort it using Bubble Sort
    cout << "Bubble Sort on array" << endl;
    int bubble_array[100];
    for (int i = 0; i < 100; i++) {
        bubble_array[i] = rand() % 100;
    }
    Sort::BubbleSort(bubble_array, 100);
    for (int i = 0; i < 100; i++) {
        cout << bubble_array[i] << " ";
    }
    cout << endl << endl;

    // create a list of random integers and sort it using Quick Sort
    cout << "Quick Sort on list" << endl;
    list.clear();
    for (int i = 0; i < 100; i++) {
        list.push_back(rand() % 100);
    }
    Sort::QuickSort(list);
    for (auto &i: list) {
        cout << i << " ";
    }
    cout << endl << endl;

    // create an array of random integers and sort it using Selection Sort
    cout << "Selection Sort on array" << endl;
    int array[100];
    for (int i = 0; i < 100; i++) {
        array[i] = rand() % 100;
    }
    Sort::SelectionSort(array, 100);
    for (int i = 0; i < 100; i++) {
        cout << array[i] << " ";
    }
    cout << endl << endl;

    // create an array of random integers and sort it using Bogo Sort
    cout << "Bogo Sort on array" << endl;
    int bogo_array[10];
    for (int i = 0; i < 10; i++) {
        bogo_array[i] = rand() % 100;
    }
    Sort::BogoSort(bogo_array, 10);
    for (int i = 0; i < 10; i++) {
        cout << bogo_array[i] << " ";
    }
    cout << endl << endl;

    // create a vector of random integers and sort it using Insertion Sort
    cout << "Insertion Sort on vector" << endl;
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
