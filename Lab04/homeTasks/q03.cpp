// Implement the Selection Sort algorithm. The program should take an array of integers from the user, find the smallest element, and exchange it with the element at the first position. This process should continue until the array is completely sorted. Display the sorted array to the user.
#include <iostream>
using namespace std;

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        int smallestIndex = i;
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[smallestIndex]) {
                smallestIndex = j; 
            }
        }
        int temp = arr[i]; 
        arr[i] = arr[smallestIndex];
        arr[smallestIndex] = temp;
    }
}

int main() {
    int n;
    cout << "enter elementws: " ;
    cin >> n;

    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        int num;
        cout << "element " << i << ": ";
        cin >> num;
        arr[i] = num;
    }

    for(int i = 0; i<n;i++) {
        cout << arr[i] << "  ";
    }
    cout << endl;
    selectionSort(arr, n);

    for(int i = 0; i<n;i++) {
        cout << arr[i] << "  ";
    }
    cout << endl;
    
    delete[] arr;
}
