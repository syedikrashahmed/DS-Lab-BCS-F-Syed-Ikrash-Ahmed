i/*Task-4:Imagine you are working for a company that provides an online shopping platform. There are only 3products listed on the platform, and customers often search for products based on their price. Write aprogram in C++ that uses Quick sort to sort the products based on their price in ascending order.Define a class for each product that will store its name, price, description, and availability*/

#include <iostream>
#include <string>
using namespace std;

class Product {
public:
    string name;
    double price;
    string description;
    bool available;
    
    Product() : name(" "), price(0.0), description(" "), available(true) {}
};

int partition(Product arr[], int low, int high) {
    double pivot = arr[high].price;
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j].price < pivot) {
            i++;
            Product temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    swap(arr[i + 1], arr[high]);
    Product temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}

void quickSort(Product arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n = 3;
    Product products[3];
    for (int i = 0; i < n; i++) {
        cout << "\nProduct " << i + 1 << " name: ";
        cin >> products[i].name;
        cout << "Price: ";
        cin >> products[i].price;
        cout << "Description: ";
        cin >> products[i].description;
        cout << "Available (1 for Yes, 0 for No): ";
        cin >> products[i].available;
    }

    quickSort(products, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << "Name: " << products[i].name << endl;
        cout << "Price: Rs." << products[i].price << endl;
        cout << "Description: " << products[i].description << endl;
        cout << "Available: " << (products[i].available ? "Yes" : "No") << endl;
    }
}p