/*5. Implement the Interpolation Search algorithm. The program should take a sorted array
with uniformly distributed values and a target value from the user. The algorithm should
estimate the position of the target and check if the estimated position holds the correct
value. If the element is found, print its index; otherwise, indicate that it's not present.*/

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

bool isUniformlyDistributed(int* arr, int n) {
    int space = arr[1] - arr[0];
    for (int i = 1; i < n - 1; i++) {
        if (space != arr[i + 1] - arr[i]) {
            return false;
        }
    }
    return true;
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

    if (isUniformlyDistributed(arr, n)) {
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
    }
}
