/*Task #3:
Design a program to handle marks of students in different courses using a jagged array
(since each student is enrolled in a different number of courses).
=> Input the number of courses each student takes.
=> Dynamically allocate memory for each student accordingly.
=> Calculate and display each student’s average marks.*/

#include <iostream>
using namespace std;

int main() {
    int numStds;
    int **arr, *numCourses;
    cout << "Enter number of students: ";
    cin >> numStds;
    numCourses = new int[numStds];
    for (int i = 0; i < numStds; i++) {
        cout << "Enter num of courses for Student " << i << ": ";
        cin >> numCourses[i];
    }
    
    arr = new int*[numStds];
    for (int i = 0; i < numStds; i++) {
        arr[i] = new int[numCourses[i]];
    }
    
    for (int i = 0; i < numStds; i++) {
        for (int j = 0; j < numCourses[i]; j++) {
            int element;
            cout << "Enter students marks for Student " << i << "Course " << j << ": ";
            cin >> element; 
            arr[i][j] = element;
        }
    }
    
    for (int i = 0; i < numStds; i++) {
        float total = 0.0;
        float average;
        for (int j = 0; j < numCourses[i]; j++) {
            total += arr[i][j];
        }
        average = total / numCourses[i];
        cout << "Average marks for Student " << i << ": " << average << endl;
    }
    
    for (int i = 0; i < numStds; i++) {
        delete [] arr[i];
    }
    delete [] arr;
    delete [] numCourses;
}
