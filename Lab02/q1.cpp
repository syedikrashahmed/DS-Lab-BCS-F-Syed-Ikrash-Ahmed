// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

int main() {
    int *arr;
    int size;
    cout << "Enter size: ";
    cin >> size;
    arr = new int[size];
    for (int i = 0; i < size; i++) {
        arr[i] = 0;
    }
    
    while (true) {
        int num, pos;
        cout << "Input position to update (-1 to stop): ";
        cin >> pos;
        if (pos == -1) {
            break;
        }
        else if (pos < 0 || pos >= size) {
            cout << "Invaid position" << endl;
            continue;
        }
        else {
            cout << "Input element " << pos << ": ";
            cin >> num;
            arr[pos] = num;
        }
    }
    
    for (int i = 0; i < size; i++) {
        cout << "Element " << i << ": " << arr[i] << endl;
    }
    
    delete [] arr;
}
