
#include <iostream>
using namespace std;

void bubbleSort(int *arr, int n) {
    bool swapped = false;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
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
    int arr[] = {5,1,3,6,2,9,7,4,8,10};
    for (int i = 0; i < 10; i++) {
        cout << arr[i] << " ";
    }
    cout << endl << endl;
    bubbleSort(arr, 10);
    for (int i = 0; i < 10; i++) {
        cout << arr[i] << " ";
    }
}
