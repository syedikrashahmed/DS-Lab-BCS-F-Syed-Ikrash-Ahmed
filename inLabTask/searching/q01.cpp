/*Write a C++ program to implement Linear Search. Your program should take an array of integers and a target value as input from the user. The program should search for the target value in the array using the linear search algorithm and output the index at which the target is found. If the target value is not found in the array, the program should display an appropriate message.*/

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
    cout << "Enter num elements for array: ";
    cin >>n;
    int* arr = new int[n];
    for (int i =0; i< n; i++) {
        cout << "Element " << i<<": ";
        int num;
        cin >> num;
        arr[i] = num;
    }
    int target;
    cout << "Target to search: ";
    cin >> target;
    int search = linearSearch(arr,target, n);
    if (search == -1) {
        cout << "not found"<<endl;
    }
    else {
        cout << "index: "<< search<<endl;
    }

    delete []arr;
}
