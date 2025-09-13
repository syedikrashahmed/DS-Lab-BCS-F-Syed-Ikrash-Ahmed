/*1. Implement a linear search algorithm to find a specific integer in an array. The program
should take an array of integers and a target value as input from the user. Print the index of
the target value if it's found or a message indicating that the element is not in the array.*/

#include <iostream>
using namespace std;

int linearSearch(int* arr, int target, int n) {
    bool found = false;
    int index;
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            found = true;
            index = i;
            break;
        }
    }
    if (found) {
        return index;
    }
    else {
        return -1;
    }
}

int main() {
    int n;
    cout << "enter elementws: ";
    cin >> n;
    int* arr = new int[n];
    for (int i=0 ;i < n; i++) {
        int num;
        cout << "Element " << i << ": ";
        cin >> num;
        arr[i] = num;
    }

    int target;
    cout << "enter target: ";
    cin >> target;

    int search = linearSearch(arr, target, n);

     if (search == -1) {
        cout << "not found"<<endl;
    }
    else {
        cout << "index: "<< search<<endl;
    }

    delete []arr;
}
