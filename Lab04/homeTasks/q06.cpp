/*6. Implement the Comb Sort algorithm to sort an array of integers. This algorithm improves
upon bubble sort by reducing the number of comparisons and swaps using a "gap" that
decreases over time. After sorting, perform a complexity analysis: count and display the
total number of swaps and comparisons performed during the sorting process.*/

#include <iostream>
using namespace std;

void combSort(int* &arr, int n) {
    int swaps = 0;
    int comparisions = 0;
    int gap = n;
    bool swapped = true;

    while (gap != 1 || swapped == true) {
        gap = int(gap / 1.3);
        if (gap < 1) {
            gap = 1;
        }
        swapped = false;
        
        for (int i = 0; i < n - gap; i++) {
            comparisions++;
            if (arr[i] > arr[i  + gap]) {
                int temp = arr[i];
                arr[i] = arr[i + gap];
                arr[i + gap] = temp;
                swaps++;
                swapped = true;
            }
        }
    }

    cout << "Comparisions: " << comparisions << endl << "Swaps: "<<swaps <<endl;
}

int main() {
    int n;
    cout << "Total elements: ";
    cin>> n;
    int* arr = new int[n];
    for (int i =0; i<n; i++) {
        cout << "element["<< i << "]: ";
        cin >> arr[i];
    }
    combSort(arr, n);
    cout << "sorted array:" <<endl;
    for (int i =0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout <<endl;
    delete[] arr;
}
