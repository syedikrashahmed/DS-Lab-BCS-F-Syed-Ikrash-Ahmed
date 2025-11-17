/*Task-3:Suppose you are working for a company that organizes a marathon every year. There are 10participants in the marathon, and their finish times are recorded in seconds.
Write a program in C++ that uses Merge sort to find the top 5 fastest runners. Create an array ofrunner objects that will store the participant's name and finish time in seconds.
● Prompt the user to input the participant's names and finish times into the array.
● Implement a merge function that will merge two subarrays of runners based on their finishtime in ascending order.
● Use the Merge sort algorithm to sort the runners based on their finish time by calling themerge function in step 3.
● Display the top 5 fastest runners to the console, along with their name and finish time inseconds.
● Use the appropriate data types and size for the arrays and variables to ensure efficientmemory usage.*/

#include <iostream>
#include <string>
using namespace std;

struct Runner {
    string name;
    int time; 
};

void merge(Runner arr[], int start, int mid, int end) {
    int size = end - start + 1;
    Runner* temp = new Runner[size];
    int i = start;
    int j = mid + 1;
    int k = 0;

    while (i <= mid && j <= end) {
        if (arr[i].time <= arr[j].time) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= end) {
        temp[k++] = arr[j++];
    }

    for (int t = 0; t < size; t++) {
        arr[start + t] = temp[t];
    }

    delete[] temp;
}

void mergeSort(Runner arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    int n = 10;
    Runner runners[10];
    for (int i = 0; i < n; i++) {
        cout << "Runner " << i + 1 << " name: ";
        cin >> runners[i].name;
        cout << "Finishing time of " << runners[i].name << ": ";
        cin >> runners[i].time;
    }

    mergeSort(runners, 0, n - 1);

    for (int i = 0; i < 5; i++) {
        cout << i + 1 << ") " << runners[i].name << " - " << runners[i].time << " secs\n";
    }
}