/*Your team has been given a large dataset (input by user) of sorted, uniformly distributed account balances. If the data is not sorted, you have to sort it first. If the data is not uniformly distributed after you apply sorting (if necessary) you can prompt an error. Your manager has asked you to implement Interpolation Search because it estimates the position of the target value based on the data distribution. This will allow the search to "jump" closer to the target in fewer iterations.*/

#include <iostream>
using namespace std;

int interpolationSearch(int* arr, int n, int target) {
    int low = 0; 
    int high = n - 1; 

    while (target <= arr[high] && target >= arr[low] && low <= high) { 
        int probe = low + (high - low) * (target - arr[low]) / (arr[high] - arr[low]);  

        if (arr[probe] == target) {
            return probe;
        }
        else if (arr[probe] < target) {
            low = probe + 1; 
        }
        else {
            high = probe - 1;
        }
    }
    return -1;
}

bool isSorted(int* arr, int n) {
    bool sorted = true;
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            sorted = false;
        }
    }
    return sorted;
}

bool isUniformlyDistributed(int* arr, int n) {
    int space = arr[1] - arr[0];
    for (int i = 1; i < n - 1; i++) {
        if (space != arr[i + 1] - arr[i]) {
            return false;
        }
    }
    return true;
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
    cout << "Enter size of dataset: ";
    cin >> n;
    int* arr = new int[n];
    cout << "enter data:"<<endl;
    for (int i =0; i< n; i++) {
        cout << "element "<< i << ": ";
        int num;
        cin >> num;
        arr[i] = num;
    }
    if (isSorted(arr, n)) {
        cout << "dataset is sorted" <<endl;
    }
    else {
        cout << "dataset is not sorted" <<endl;
        bubbleSort(arr, n);
        cout << "sotred dataset:"<<endl;
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    if (isUniformlyDistributed(arr, n)) {
        cout << "dataset is uniformly distributed" <<endl;
        int target;
        cout << "enter target to search: ";
        cin >> target;
        int index = interpolationSearch(arr, n, target);
        if (index == -1) {
            cout << "not found"<<endl;
        }
        else {
            cout << "found at index "<< index <<endl;
        }
    }
    else {
        cout << "error not uniformly distributed" <<endl;
        return -1;
    }
}
