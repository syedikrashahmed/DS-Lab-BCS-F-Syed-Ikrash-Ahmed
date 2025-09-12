/*You've been given an array of numbers representing employee IDs. Your task is to identify the employee whose ID matches the last two digits of your roll number. If your roll number's last two digits are not present in the array, insert the missing value in its correct position within the array. You must use binary search to locate the position of that value within the array.*/

#include <iostream>
using namespace std;

int binarySearch(int *arr, int target, int n) {
    int left = 0;
    int right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;  
        }
        else if (arr[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1; 
}

void bubbleSort(int arr[], int size) {
    bool swapped = false;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
                swapped = true;
            }
        }
        
        if (swapped == false) {
            return;
        }
    }
}

int main() {
    int n;
    cout << "Enter num employee ids for array: ";
    cin >>n;
    int* arr = new int[n];
    for (int i =0; i< n; i++) {
        cout << "employee " << i<<": ";
        int num;
        cin >> num;
        arr[i] = num;
    }
    int target = 98;
    int search = binarySearch(arr,target, n);
    if (search == -1) {
        int* newarr = new int[n + 1];
        for (int i = 0; i< n; i++) {
            newarr[i] = arr[i];
        }
        newarr[n] = target;
        delete[] arr;
        arr = newarr;
        delete[] newarr;
        n++;
        bubbleSort(arr, n);
        cout<<"printing new array"<<endl;
        for (int i = 0; i< n; i++) {
            cout << arr[i] << " ";
        }
        cout<<endl;
    }
    else {
        cout << "index: "<< search<<endl;
    }
    
    delete []arr;
}
