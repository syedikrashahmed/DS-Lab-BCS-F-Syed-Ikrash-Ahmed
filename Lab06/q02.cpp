/*Task 2 – Stack with Linked List
Implement a stack using linked lists. Demonstrate its use with a real-life example (e.g., browser
history navigation).*/


#include <iostream>
#include <string>
using namespace std;


class Node {
public:
    string data;
    Node* next;
   
    Node(string value) : data(value), next(nullptr) {}
};


class Stack {
    Node* top;
   
public:
    Stack() : top(nullptr) {}
   
    bool is_empty() {
        return top == nullptr;
    }
   
    void push(string val) {
        Node* newNode = new Node(val);
        newNode->next = top;
        top = newNode;
        cout << "pushed: " << val << endl;
    }
   
    void pop() {
        if (is_empty()) {
            cout << "No more history" << endl;
            return;
        }
       
        Node* temp = top;
        top = top->next;
        cout << "popped: " << temp->data << endl;
        delete temp;
    }
   
    string peek() {
        if (is_empty()) {
            return "No current page";
        }
        return top->data;
    }
   
    void display() {
        if (is_empty()) {
            cout << "History is empty" << endl;
            return;
        }
       
        cout << "Browser History:" << endl;
        Node* temp = top;
        int count = 1;
        while (temp != nullptr) {
            cout << count << ". " << temp->data << endl;
            temp = temp->next;
            count++;
        }
    }
};


int main() {
    Stack history;


    history.push("youtube");
    history.push("friv");
    history.push("twitter");
    history.push("pinterest");
   
    cout << "Current page: " << history.peek() << endl;
    history.display();
   
    history.pop();
    cout << "Now at: " << history.peek() << endl;
    history.pop();
    cout << "Now at: " << history.peek() << endl;
   
    history.push("wikipedia");
    history.push("guthib");
   
    cout << "Current page: " << history.peek() << endl;
    history.display();
}
