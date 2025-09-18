/*You are asked to sort a list of product prices for a retail store using Comb Sort. However, instead of using the standard shrink factor of 1.3 (as typically used in Comb Sort), you must create and implement a custom shrink factor of your choice that you think can align with the problem.*/

#include <iostream>
using namespace std;

void print(int* &arr, int n) {
    for (int i =0; i< n; i++) {
        cout << arr[i] << " ";
    }
    cout <<endl;
}

void combSort(int* &arr, int n) {
    int gap = n;
    bool swapped = true;

    while (gap != 1 || swapped == true) {
        gap = int(gap / 1.5);
        if (gap < 1) {
            gap = 1;
        }
        swapped = false;
        
        for (int i = 0; i < n - gap; i++) {
            if (arr[i] > arr[i  + gap]) {
                int temp = arr[i];
                arr[i] = arr[i + gap];
                arr[i + gap] = temp;
                swapped = true;
            }
        }
    }
    cout << "sort by comb sort with shrink factor 1.5:"<<endl;
    print(arr, n);
}

int main() {
   int n;
    cout << "Enter size of array: ";
    cin >> n;
    int* arr = new int[n];
    cout << "enter data:"<<endl;
    for (int i =0; i< n; i++) {
        cout << "element "<< i << ": ";
        int num;
        cin >> num;
        arr[i] = num;
    }
    combSort(arr, n);
}