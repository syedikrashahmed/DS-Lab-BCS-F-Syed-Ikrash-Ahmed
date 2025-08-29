/*Task #7:
A company has multiple departments, each department has a different number of employees.
=> Use a jagged array where each row corresponds to a department and columns store employee
salaries.
Calculate:
-> The highest salary in each department.
-> The department with the overall maximum average salary.*/

#include <iostream>
using namespace std;

int main() {
    int numDepts, *numEmps;
    cout << "Num Departments: ";
    cin>> numDepts;
    float** salaries = new float*[numDepts];
    string* depts = new string[numDepts];
    numEmps = new int[numDepts];
    for (int i =0;i<numDepts;i++) {
        cout << "Name of Department " << i + 1<< ": ";
        cin>> depts[i];
        cout << "Number of empolyees in " << depts[i] << ":";
        cin>> numEmps[i];
        salaries[i] = new float[numEmps[i]];
    }

    for (int i =0;i<numDepts;i++) {
        for (int j=0; j< numEmps[i];  j++) {
            cout << "salary of employee " << j+1<< " of departemnt "<< depts[i] << ":";
            cin >> salaries[i][j];
        }
    }

    float* avgs= new float[numDepts];
    for (int i =0;i<numDepts;i++) {
        float highest= -1, total = 0;
        for (int j=0; j< numEmps[i];  j++) {
            total += salaries[i][j];
            if (salaries[i][j] > highest) {
                highest = salaries[i][j];
            }
        }
        cout << "Hishest salary in " << depts[i] << " is " << highest << endl;
        avgs[i] = total / numEmps[i];
    }

    float highest = -1; int index;
    for (int i = 0; i<numDepts;i++) {
        if(avgs[i]> highest) {
            highest = avgs[i];
            index = i;
        }
    }
    cout << "Highest salary average of " << highest << " is of " << depts[index] << endl;

    for (int i = 0; i < numDepts; i++) {
        delete[] salaries[i];
    }
    delete[] salaries;
    delete[] numEmps;
    delete[] avgs;
    delete[] depts;
}
