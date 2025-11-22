/*Task # 4: Given an array of distinct integers, find using hashing if there are two pairs (a, b) and (c, d) such that a+b = c+d, and a, b, c, and d are distinct elements. If there are multiple answers, then print any of them.
Input: {3, 4, 7, 1, 2, 9, 8}; Output: (3, 8) and (4, 7); Explanation: 3+8 = 4+7
Input: {3, 4, 7, 1, 12, 9}; Output: (4, 12) and (7, 9); Explanation: 4+12 = 7+9
Input: {65, 30, 7, 90, 1, 9, 8}; Output: No pairs found*/
#include <iostream>
#include <string>
using namespace std;

void findPairs(int arr[], int n) {
    int sums = 1000; 
    int *pair1 = new int[sums];  
    int *pair2 = new int[sums];  
    bool *sumExists = new bool[sums](); 
    for (int i = 0; i < sums; i++) {
        sumExists[i] = false;
        pair1[i] = 0;
        pair2[i] = 0;
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int sum = arr[i] + arr[j];
            if (sumExists[sum]) {
                int a = pair1[sum];
                int b = pair2[sum];
                if (a != arr[i] && a != arr[j] && b != arr[i] && b != arr[j]) {
                    cout << "(" << a << ", " << b << ") and ";
                    cout << "(" << arr[i] << ", " << arr[j] << ")" << endl;
                    return;
                }
            } 
            else {
                pair1[sum] = arr[i];
                pair2[sum] = arr[j];
                sumExists[sum] = true;
            }
        }
    }
    cout << "No pairs found" << endl;
}

int main() {
    int arr1[] = {3, 4, 7, 1, 2, 9, 8};
    int n = 7;
    findPairs(arr1, n);
}
