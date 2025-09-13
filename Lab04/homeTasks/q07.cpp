/*7. Implement the Shell Sort algorithm to sort an array of integers. The algorithm should start
with a large gap, then perform a gapped insertion sort, and gradually reduce the gap until
it's 1. After sorting, compare its performance against the Bubble Sort and Insertion Sort
algorithms for the same input array size (e.g., 1000 elements). Record and display the time
taken and the number of comparisons/swaps for all three algorithms to demonstrate why
Shell Sort is an improvement over Insertion Sort.*/

#include <iostream>
using namespace std;

void print(int* &arr, int n) {
    for (int i =0; i< n; i++) {
        cout << arr[i] << " ";
    }
    cout <<endl;
}

void shellSort(int arr[], int n) {
    int swaps = 0, comparisions = 0;
    for (int gap = n/2; gap > 0; gap/= 2) {
        for (int j = gap; j < n; j++) {
            int temp = arr[j];
            int i = 0;
            for (i = j; i >= gap && arr[i - gap] > temp; i-= gap) {
                arr[i] = arr[i - gap];
                comparisions++;
                swaps++;
            }
            arr[i] = temp;
        }
    }
    cout << "Sort by Shell Sort:" <<endl;
    print(arr, n);
    cout << "Comparisions: "<< comparisions << endl << "Swaps: "<<swaps <<endl;
}

void insertionSort(int arr[], int n) {
    int swaps = 0, comparisions = 0;
    for (int i = 1; i < n; i++) {
        int current = arr[i];
        int prev = i - 1;
        
        while (current < arr[prev] && prev >= 0) {
            arr[prev + 1] = arr[prev];
            prev--;
            comparisions++;
            swaps++;
        }
        
        arr[prev + 1] = current;
    }
    cout << "Sort by Insertion Sort:" <<endl;
    print(arr, n);
    cout << "Comparisions: "<< comparisions << endl << "Swaps: "<<swaps <<endl;
}

void bubbleSort(int arr[], int n) {
    int swaps = 0, comparisions = 0;
    bool swapped = false;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
                swapped = true;
                comparisions++;
                swaps++;
            }
        }
        
        if (swapped == false) {
            return;
        }
    }
    cout << "Sort by Bubble Sort:" <<endl;
    print(arr, n);
    cout << "Comparisions: "<< comparisions << endl << "Swaps: "<<swaps <<endl;
}

int main() {
    int n;
    cout << "Total elements: ";
    cin>> n;
    int* arr1 = new int[n];
    int* arr2 = new int[n];
    int* arr3 = new int[n];
    for (int i =0; i<n; i++) {
        cout << "element["<< i << "]: ";
        cin >> arr1[i];
        arr2[i] = arr3[i] = arr1[i];
    }
    shellSort(arr1, n);
    insertionSort(arr2, n);
    bubbleSort(arr3, n);
    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
}
