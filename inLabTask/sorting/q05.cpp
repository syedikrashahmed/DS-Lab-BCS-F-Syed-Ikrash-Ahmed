/* Develop C++ solution such that day month and year are taken as input for 5 records and perform Sorting Dates based on year using Selection Sort. 
Note: Input must be taken from user.
[Hint: Struct or Class can be used]
It`s not strictly necessary to take inputs in the format as shown in example, but, the output should be in the given format.

Example Input:
01/02/2022
5/01/2018
4/07/2015
12/10/2021
11/12/2023

Example Output:
4/07/2015
5/01/2018
12/10/2021
01/02/2022
11/12/2023
*/

#include <iostream>
using namespace std;

class Date {
public:
    int day, month, year;

    Date() : day(0), month(0), year(0) {}
    Date(int d, int m, int y) : day(d), month(m), year(y) {}
    void print() { cout << day << "/" << month << "/" << year << endl; }
};

void selectionSort(Date arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j].year < arr[minIndex].year) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            Date temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

int main() {
    Date dates[5];
    cout << "Enter dates:" << endl;
    for (int i = 0; i < 5; i++) {
        int d, m, y;
        cin >> d;
        cin >> m;
        cin >> y;
        dates[i] = Date(d, m, y);
    }
    selectionSort(dates, 5);
    for (int i = 0; i < 5; i++) {
        dates[i].print();
    }
}