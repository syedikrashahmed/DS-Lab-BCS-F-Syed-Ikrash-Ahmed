/*4.   In a bustling corporate office, the facilities management team is tasked with organizing the 
seating
arrangements for employees based on their designations. The office layout consists of rows of 
computer desks, and each desk has a designated employee. The priority is to sort out the computer 
desks for employees using the Insertion Sort algorithm, with the designation determining the 
sorting order. The higher the designation, the closer the employee should be seated to the comer 
office. The designations and their corresponding priorities are as follows:
1.   CEO (Chief Executive Officer) - Highest Priority
11.    CTO (Chief Technology Officer)
111.    CFO (Chief Financial Officer) 1v.   VP (Vice President)
v.   MGR (Manager)
v1.   EMP (Employee) - Lowest Priority

Here's the initial arrangement of employees' desks from left to right:
1.   Employee (EMP)
11.   CFO (Chief Financial Officer)
111.   Manager (MGR) 1v.   Employee (EMP)
v.   VP (Vice President)
v1.   CTO (Chief Technology Officer) v11.   Manager (MGR)
vn1.  CEO (Chief Executive Officer)*/

#include <iostream>
using namespace std;

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int current = arr[i];
        int prev = i - 1;
        while (current < arr[prev] && prev >= 0) {
            arr[prev + 1] = arr[prev];
            prev--;
        }
        arr[prev + 1] = current;
    }
}

int main() {
    int ceo = 0;
    int cto = 1;
    int cfo = 2;
    int vp = 3;
    int mgr = 4;
    int emp = 5;

    int n = 8;
    int arr[n] = {emp, cfo, mgr, emp, vp, cto, mgr, ceo};
    insertionSort(arr, n);

    for (int i = 0; i < n; i++) {
        switch (arr[i])
        {
        case 0:
            cout << "ceo ";
            break;
        
        case 1:
            cout << "cto ";
            break;

        case 2:
            cout << "cfo ";
            break;
        
        case 3:
            cout << "vp ";
            break;

        case 4:
            cout << "mgr ";
            break;
        
        case 5:
            cout << "emp ";
            break;


        default:
            break;
        }
    }
}
