/*Task #6:
Implement a Safe Pointer class to wrap around an integer pointer.
=> Provide methods for setValue(), getValue(), and release().
=> Demonstrate the class by storing marks of 5 students and printing them safely without direct pointer manipulation.*/

#include <iostream>
using namespace std; 

class SafePtr {
    int* ptr;
    int size;

    public:
    SafePtr() : ptr(nullptr), size(0) {}

    SafePtr(int size) : size(size) {
        ptr = new int[size];
        for (int i =0; i < size; i++) {
            ptr[i] =0;
        }
    }

    SafePtr(SafePtr &ptr1) {
        size = ptr1.size;
        ptr = new int[size];
        for (int i = 0; i< size; i++) {
            ptr[i] = ptr1.ptr[i];
        }
    }

    void setValue(int pos, int value) {
        if (pos< 0 || pos>= size ) {
            cout << "Invalid position" << endl;
            return;
        }
        ptr[pos] = value;
        cout << value <<" set at position " << pos << endl;
    }

    int getValue(int pos) {
        if (pos< 0 || pos>= size ) {
            cout << "Invalid position" << endl;
            return -111;
        }
        return ptr[pos];
    }

    void release() {
        cout << "releasing pointer" <<endl;
        size = 0;
        delete[] ptr;
        ptr = nullptr;
    }

    ~SafePtr() {
        delete[] ptr;
    }
}; 

int main() {
    int size, num; 
    cout << "What size array for students marks do you want: ";
    cin>>size;
    SafePtr ptr(size);
    cout << "array of "<< size << " students marks is created"<<endl;
    cout << "Populate the array:"<<endl;
    for (int i =0; i< size; i++) {
        cout << "Student "<< i<<": ";
        cin >> num;
        ptr.setValue(i, num);
    }
    cout <<"Displaying the marks:"<<endl;
    for (int i =0; i< size; i++) {
        cout << "Student "<< i <<": "<< ptr.getValue(i) <<endl;
    }
    cout << "Enter position of value to get:";
    cin >> num;
    num = ptr.getValue(num);
    if (num != -111) {
        cout << "Marks: "<< num << endl;
    }   
    ptr.release();
}
