/*Task #4:
Create a dynamic program that manages monthly expenses for a family.
=> Use a 1D dynamic array to store expenses for n months.
=> Add a feature to resize the array if the user wants to track more months later.
=> Compute and display the total and average expenses.*/

#include <iostream>
using namespace std;

int main() {
    int *arr;
    int numMonths;
    cout << "Enter num months: ";
    cin >> numMonths;
    arr = new int[numMonths];
    
    cout << "Enter expenes:" << endl;
    for(int i = 0 ; i<numMonths; i++) {
        cout << "Month" << i + 1 <<": ";
        cin >> arr[i];
    }
    
    char choice;
    cout << "more months? (y/n): ";
    cin >> choice;
    if (choice == 'y' ){
        int addMonths;
        cout << "How many more months? "  ;
        cin >> addMonths;
        int *newArr = new int[numMonths + addMonths];
        
        for(int i = 0  ; i <numMonths; i++) {
            newArr[i] = arr[i];
        }
        
        cout << "Enter expenses for more months:" << endl;
        for(int i = numMonths; i < numMonths + addMonths; i++) {
            cout << "Month " << i + 1 << ": ";
            cin >> newArr[i];
        }
        
        int total = 0;
        for (int i = 0; i < numMonths; i++) {
            total += arr[i];
        }
        float average = total / numMonths;
        cout << "Total:" << total << endl;
        cout << "Averages:" << average << endl;
        delete[] arr;
        arr = newArr;
        numMonths += addMonths;
    }
    
    delete[] arr;
}
