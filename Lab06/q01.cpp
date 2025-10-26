/*Task 1 – Basic Stack Implementation
Implement a stack using arrays. Support the following operations:
1. Push an element
2. Pop an element
3. Peek (top element)
4. Display stack contents*/


#include <iostream>
using namespace std;


class myStack {
    int size;
    int top;
    int* arr;
   
    public:
    myStack(int size) : size(size), top(-1) {
        arr = new int[size];
    }


    bool empty() {
        if (top == -1) {
            return true;
        }
        else {
            return false;
        }
    }
   
    bool full() {
        if (top == size - 1) {
            return true;
        }
        else {
            return false;
        }
    }
   
    void push(int val) {
        if (full()) {
            cout << "Stack is full, cannot push" << endl;
            return;
        }
       
        top++;
        arr[top] = val;
        cout << "Value pushed" <<endl;
    }
   
    void pop() {
        if (empty()) {
            cout << "Stack is empty, cannot pop" << endl;
            return;
        }
       
        top--;
        cout << "Value popped" <<endl;
    }
   
    void peek(int pos) {
        if (pos < 0 || pos > size -1 || pos > top) {
            cout << "Invalid" << endl;
            return;
        }
       
        cout << "Element at position " << pos << " is " << arr[pos] << endl;
        return;
    }
   
    void displayStack() {
        if (top == -1) {
            cout << "Stack is empty" << endl;
            return;
        }
       
        cout << "Printing stack: " << endl;
        for (int i = 0; i <= top; i++) {
            cout << i << ") " << arr[i] << endl;
        }
        cout << endl;
    }
   
    ~myStack() {
        delete[] arr;
    }
};


int main() {
    myStack stack(5);
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.displayStack();
    stack.peek(2);
    stack.pop();
    stack.displayStack();
    stack.peek(2);
    stack.push(40);
    stack.push(50);
    stack.push(60);
    stack.push(70);
    stack.push(80);
    stack.displayStack();
}

