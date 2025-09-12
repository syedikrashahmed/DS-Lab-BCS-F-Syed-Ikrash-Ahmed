/*5. Convert Between Linked List Types
Implement functions for conversion:
1. Convert a singly linked list into a doubly linked list.
2. Convert a singly linked list into a circular linked list.
• Demonstrate both conversions with sample input lists.*/

#include <iostream>
using namespace std;

class singlyNode {
    public:
    int data;
    singlyNode* next;

    singlyNode(int val) : data(val), next(nullptr) {} 
};

class doublyNode {
    public:
    int data;
    doublyNode* next;
    doublyNode* prev;

    doublyNode(int val) : data(val), next(nullptr), prev(nullptr) {} 
};

class SinglyLL {
    public:
    singlyNode* head;
    singlyNode* tail;

    SinglyLL() : head(nullptr), tail(nullptr) {}

    void pushBack(int val) {
        singlyNode* newNode = new singlyNode(val);
        if (head == nullptr) {
            head = tail = newNode;
            return;
        }

        tail->next = newNode;
        tail = newNode;
    }

    void print() {
        if (head == nullptr) {
            cout << "List empty" <<endl;
            return;
        }
        singlyNode* temp = head;
        while (temp != tail) {
            cout << temp->data << ", ";
            temp = temp->next;
        }
        cout << temp->data << endl;
    }

    void printCircular() {
        if (head == nullptr) {
            cout << "empty"<<endl;
            return;
        }

        singlyNode* temp = head;
        while (temp != tail) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl << "Tail: " << temp->data <<endl;
        temp = temp->next;
        while (temp != tail) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

    ~SinglyLL() {
        singlyNode* temp = head;
        while (temp != nullptr) {
            singlyNode* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
        delete temp;
        delete head;
        delete tail;
    }
};

class DoublyLL {
    public:
    doublyNode* head;
    doublyNode* tail;

    DoublyLL() : head(nullptr), tail(nullptr) {}

    void pushBack(int val) {
        doublyNode* newNode = new doublyNode(val);
        if (head == nullptr) {
            head = tail = newNode;
            return;
        }

        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    void pushBackSingly(int val) {
        doublyNode* newNode = new doublyNode(val);
        if (head == nullptr) {
            head = tail = newNode;
            return;
        }

        tail->next = newNode;
        newNode->prev = nullptr;
        tail = newNode;
    }

    void printForward() {
        if (head == nullptr) {
            cout << "List empty" <<endl;
            return;
        }
        doublyNode* temp = head;
        while (temp != tail) {
            cout << temp->data << ", ";
            temp = temp->next;
        }
        cout << temp->data << endl;
    }

    void printBackward() {
        if (tail == nullptr) {
            cout << "List empty" <<endl;
            return;
        }
        doublyNode* temp = tail;
        while (temp != head) {
            cout << temp->data << ", ";
            temp = temp->prev;
        }
        cout << temp->data << endl;
    }

    ~DoublyLL() {
        doublyNode* temp = head;
        while (temp != nullptr) {
            doublyNode* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
        delete temp;
        delete head;
        delete tail;
    }
};

void singlyToDoubly(DoublyLL &list) {
    if (list.head == nullptr) {
        return;
    }

    doublyNode* temp = list.head;
    doublyNode* next = list.head->next;
    doublyNode* prev = list.head;

    while(next != nullptr) {
        temp = next;
        temp->prev = prev;
        prev = next;
        next = next->next;
    }
}

void singlyToCircular(SinglyLL &list) {
    if (list.head == nullptr) {
        return;
    }
    list.tail->next = list.head;
}

int main() {
    SinglyLL list1;
    list1.pushBack(1);
    list1.pushBack(2);
    list1.pushBack(3);
    list1.pushBack(4);
    list1.pushBack(5);
    list1.print();
    singlyToCircular(list1);
    list1.printCircular();
    cout << endl;

    DoublyLL list2;
    list2.pushBack(1);
    list2.pushBack(2);
    list2.pushBack(3);
    list2.pushBack(4);
    list2.pushBack(5);
    list2.printForward();
    singlyToDoubly(list2);
    list2.printBackward();

}
