/* Create a C++ class Box that uses dynamic memory allocation for an integer. Implement the Rule of Three by defining a destructor, copy constructor, and copy assignment operator. Demonstrate the behavior of both shallow and deep copy using test cases.*/

#include <iostream>
using namespace std;

class Box {
    public:
    int *number;

    Box() {
        number = nullptr;
    }
    Box(int num) {
        number = new int();
        *number = num;
    }
    Box(Box &b1) {
        number = new int();
        *number = *b1.number;
    }
    Box& operator=(const Box &b1) {
        delete number;
        number = new int();
        *number = *b1.number;
        return *this;
    }
    void printNum() {
        cout << "Number: " << *number << endl;
    }
    ~Box() {
        delete number;
    }
};

int main() {
    cout << "box b1 and b2 created with these values: " << endl;
    Box b1(10);
    cout << "b1: ";
    b1.printNum();
    Box b2(20);
    cout << "b2: ";
    b2.printNum();

    cout << "box b3 created using copy constructor by copying b1: " << endl;
    Box b3(b1);
    cout << "box b1 copied to b2 using copy assignment operator: " << endl;
    b1 = b2;
    cout << "after copying, b1 b2 b3 values are: " << endl;
    cout << "b1: ";
    b1.printNum();
    cout << "b2: ";
    b2.printNum();
    cout << "b3: ";
    b3.printNum();
    cout << "changing value of b1 to 30: " << endl;
    b1.number = new int(30);
    cout << "after changing b1, values are: " << endl;
    cout << "b1: ";
    b1.printNum();
    cout << "b2: ";
    b2.printNum();
    cout << "b3: ";
    b3.printNum();
    cout << "if copy constructor nd assingmnt operator was not writtten, changing b1 would have also changed b2 and b3 as all would have pointed to the same memory location" << endl;
}