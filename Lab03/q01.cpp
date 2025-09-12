/*1. Palindrome Check in Singly Linked List
Write a program to check if a singly linked list is a palindrome.
• Input: A singly linked list of integers.
• Output: true if the list reads the same forward and backward, false otherwise.*/

#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class singlyLL {
    public:
    Node* head;
    Node* tail;
    
    singlyLL() : head(nullptr), tail(nullptr) {}

    void pushFront(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = tail = newNode;
            return;
        }

        newNode->next = head;
        head = newNode;
    }

    void pushBack(int val) {
        Node* newNode = new Node(val);
        if (tail == nullptr) {
            head = tail = newNode;
            return;
        }

        tail->next = newNode;
        tail = newNode;
    }

    void popFront() {
        if (head == nullptr) {
            cout << "List empty" << endl;
            return;
        }

        if (head == tail) {
            delete head;
            head = tail = nullptr;
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void popBack() {
        if (tail == nullptr) {
            cout << "List empty" << endl;
            return;
        }

        if (head == tail) {
            delete tail;
            head = tail = nullptr;
            return;
        }

        Node* temp = head;
        while (temp->next != tail) {
            temp = temp->next;
        }
        Node* toDelete = tail;
        tail = temp;
        delete toDelete;
    }

    ~singlyLL() {
        Node* temp = head;
        while (temp != nullptr) {
            Node* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
        delete temp;
        delete head;
        delete tail;
    }
};

bool isPalindrome(singlyLL &ll) {
    if (ll.head == nullptr) {
        return true;
    }
    int total = 0;
    Node* temp = ll.head;
    while (temp != ll.tail) {
        total++;
        temp = temp->next;
    }
    int back = total;
    int front = 0;
    Node* frontptr = ll.head;
    bool check = true;
    while (front < back ) {
        temp = ll.head;
        for (int i = 0; i < back; i++) {
            temp = temp->next;
        }
        if (temp->data != frontptr->data) {
            check = false;
            break;
        }
        back--;
        front++;
        frontptr = frontptr->next;
    }
    return check;
}

int main() {
    singlyLL ll;
    ll.pushFront(1);
    ll.pushFront(2);
    ll.pushFront(3);
    ll.pushFront(2);
    ll.pushFront(1);
    if (isPalindrome(ll)) {
        cout << "Palindrome!!";
    }
    else {
        cout << "Not a Palindrome!!";
    }
}
