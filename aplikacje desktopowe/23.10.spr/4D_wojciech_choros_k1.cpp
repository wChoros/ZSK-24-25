#include <iostream>

using namespace std;

// Dana jest struktura zawierajaca dane dot ksiazki.
// Autor, tytul, rok wydania.
// Utworz kolejke dynamiczną zawierającą kilka elementow tej struktury.
// Napisz funkcje sprawdzającą czy w kolejce znajduje się co najmniej jedna ksiazka podanego autora.

// Utwórz tablicę 2D (przez wskaźnik) zawierającą liczby typu float.

struct Book {
    string author;
    string title;
    int year;
};

struct Node {
    Book book;
    Node *next;
};

struct Queue {
    Node *head;
    Node *tail;
};

void push(Queue &queue, const Book &book) {
    Node *newNode = new Node;
    newNode->book = book;
    newNode->next = nullptr;

    if (queue.head == nullptr) {
        queue.head = newNode;
        queue.tail = newNode;
    } else {
        queue.tail->next = newNode;
        queue.tail = newNode;
    }
}

bool isAuthorInQueue(Queue &queue, const string& author) {
    Node *current = queue.head;
    while (current != nullptr) {
        if (current->book.author == author) {
            return true;
        }
        current = current->next;
    }
    return false;
}

float** create2DArray(const int rows, const int cols) {
    float** array = new float*[rows];
    for (int i = 0; i < rows; i++) {
        array[i] = new float[cols];
    }
    srand(time(nullptr));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            array[i][j] = (float)rand() / RAND_MAX * 100;
        }
    }
    return array;
}

void delete2DArray(float** array, int rows) {
    for (int i = 0; i < rows; i++) {
        delete[] array[i];
    }
    delete[] array;
}

int main() {
    Queue queue = {nullptr, nullptr};
    push(queue, {"Adam Mickiewicz", "Dziady Cz 1", 1823});
    push(queue, {"Henryk Sienkiewicz", "Quo Vadis", 1816});
    push(queue, {"Adam Mickiewicz", "Dziady Cz 2", 1813});
    push(queue, {"Juliusz Słowacki", "Balladyna", 1830});
    cout << "Queue:" << endl;

    if (isAuthorInQueue(queue, "Adam Mickiewicz")) {
        cout << "Adam Mickiewicz is in queue" << endl;
    } else {
        cout << "Adam Mickiewicz is not in queue" << endl;
    }

    if (isAuthorInQueue(queue, "Wiesława Szymborska")) {
        cout << "Wiesława Szymborska is in queue" << endl;
    } else {
        cout << "Wiesław Szbymorska is not in queue" << endl;
    }

    cout << endl << "2D array:" << endl;

    const int rows = 5;
    const int cols = 5;
    float** array = create2DArray(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }

    delete2DArray(array, rows);

    return 0;
}
