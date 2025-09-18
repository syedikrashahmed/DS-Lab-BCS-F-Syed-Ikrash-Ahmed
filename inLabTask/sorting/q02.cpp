/*You are tasked with implementing the Shell Sort algorithm to sort the weights of employees in a company. However, instead of using the traditional gap sequence (where the gap is divided by 2), you must create and implement a custom gap sequence of your choice that you think can align with the problem.*/

#include <iostream>
using namespace std; 

void print(int* &arr, int n) {
    for (int i =0; i< n; i++) {
        cout << arr[i] << " ";
    }
    cout <<endl;
}

void shellSort(int arr[], int n) {
    for (int gap = n/2; gap > 0; gap/= 3) {
        for (int j = gap; j < n; j++) {
            int temp = arr[j];
            int i = 0;
            for (i = j; i >= gap && arr[i - gap] > temp; i-= gap) {
                arr[i] = arr[i - gap];
            }
            arr[i] = temp;
        }
    }
    cout << "Sort by Shell Sort with gap divided by 3:" <<endl;
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
    shellSort(arr, n);
}