/*2. Merge Two Sorted Singly Linked Lists
Implement a function to merge two sorted singly linked lists into one sorted list.
• Example:
o List A: 1 → 3 → 5
o List B: 2 → 4 → 6
o Output: 1 → 2 → 3 → 4 → 5 → 6
• Bonus: Solve without creating new nodes (rearrange pointers).*/

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

    void pushBack(Node* newNode) {
        if (tail == nullptr) {
            head = tail = newNode;
            return;
        }

        tail->next = newNode;
        tail = newNode;
        newNode->next = nullptr;
    }

    Node* popFront() {
        if (head == nullptr) {
            return nullptr;
        }

        if (head == tail) {
            Node* temp = head;
            head = tail = nullptr;
            return temp;
        }

        Node* temp = head;
        head = head->next;
        temp->next = nullptr;
        return temp;
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

    void print() {
        if (head == nullptr) {
            cout << "List empty" <<endl;
            return;
        }
        Node* temp = head;
        while (temp != tail) {
            cout << temp->data << ", ";
            temp = temp->next;
        }
        cout << temp->data << endl;
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

void merge(singlyLL &l1, singlyLL &l2, singlyLL &l3) {
    if (l1.head == nullptr && l2.head == nullptr) {
        return;
    }

    else if (l1.head == nullptr) {
        l3.pushBack(l2.popFront());
        merge(l1, l2, l3);
    }

    else if (l2.head == nullptr) {
        l3.pushBack(l1.popFront());
        merge(l1, l2, l3);
    }

    else if (l1.head->data <= l2.head->data) {
        l3.pushBack(l1.popFront());
        merge(l1, l2, l3);
    }

    else if (l2.head->data <= l1.head->data) {
        l3.pushBack(l2.popFront());
        merge(l1, l2, l3);
    }
}

int main() {
    singlyLL l1;
    l1.pushBack(1);
    l1.pushBack(3);
    l1.pushBack(5);
    cout << "List1: ";
    l1.print();
    singlyLL l2;
    l2.pushBack(2);
    l2.pushBack(4);
    l2.pushBack(6);
    cout << "List2: ";
    l2.print();
    singlyLL l3;
    merge(l1, l2, l3);
    cout << "List3: ";
    l3.print();
}
