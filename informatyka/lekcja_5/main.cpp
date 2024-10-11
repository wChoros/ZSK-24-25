#include <iostream>
#include <iomanip>
using namespace std;

struct Product {
    double price;
    string name;
    time_t expirationDate;

    bool isNameGreaterThan(const Product &other) const {
        return name > other.name;
    }

    bool isPriceGreaterThan(const Product &other) const {
        return price > other.price;
    }

    bool isExpirationDateGreaterThan(const Product &other) const {
        return expirationDate > other.expirationDate;
    }
};


double pow(const double base, const int exponent) {
    double result = 1.0;
    for (int i = 0; i < exponent; ++i) {
        result *= base;
    }
    return result;
}

void reverseArray(double *array, int size) {
    for (int i = 0; i < size / 2; ++i) {
        double temp = array[i];
        array[i] = array[size - i - 1];
        array[size - i - 1] = temp;
    }
}

void sortProductsByName(Product *products, int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (products[j].isNameGreaterThan(products[j + 1])) {
                Product temp = products[j];
                products[j] = products[j + 1];
                products[j + 1] = temp;
            }
        }
    }
}

void sortProductsByPrice(Product *products, int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (products[j].isPriceGreaterThan(products[j + 1])) {
                Product temp = products[j];
                products[j] = products[j + 1];
                products[j + 1] = temp;
            }
        }
    }
}

void sortProductsByExpirationDate(Product *products, int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (products[j].isExpirationDateGreaterThan(products[j + 1])) {
                Product temp = products[j];
                products[j] = products[j + 1];
                products[j + 1] = temp;
            }
        }
    }
}

void printProductsArray(const Product *products, const int size) {
    for (int i = 0; i < size; ++i) {
        cout << "Product " << i << endl;
        cout << "Name: " << products[i].name << endl;
        cout << "Price: " << products[i].price << endl;
        cout << "Expiration Date: " << put_time(localtime(&products[i].expirationDate), "%Y-%m-%d %H:%M:%S") << endl;
        cout << endl;
    }
}


int main() {
    Product products[10] = {
        {55.0, "Lemon", 1639000000},
        {10.0, "Apple", 1630000000},
        {45.0, "Honeydew", 1637000000},
        {20.0, "Cherry", 1632000000},
        {50.0, "Kiwi", 1638000000},
        {15.0, "Banana", 1631000000},
        {30.0, "Elderberry", 1634000000},
        {40.0, "Grape", 1636000000},
        {25.0, "Date", 1633000000},
        {35.0, "Fig", 1635000000}
    };

    int products_size = sizeof(products) / sizeof(products[0]);

    cout<< "Original Array:" << endl << endl;
    printProductsArray(products, products_size);

    sortProductsByName(products, products_size);

    cout<< "Sorted Products by name:" << endl << endl;
    printProductsArray(products, products_size);

    sortProductsByPrice(products, products_size);

    cout<< "Sorted Products by price:" << endl << endl;
    printProductsArray(products, products_size);

    sortProductsByExpirationDate(products, products_size);

    cout<< "Sorted Products by expiration date:" << endl << endl;
    printProductsArray(products, products_size);

}
