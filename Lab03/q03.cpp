/*3. Reverse in Groups of K
Reverse nodes of a singly linked list in groups of size k.
• Example:
o Input: 1 → 2 → 3 → 4 → 5 → 6 → 7 → 8, with k = 3
o Output: 3 → 2 → 1 → 6 → 5 → 4 → 8 → 7*/

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

void reverse(singlyLL &list, int k) {
    if (list.head == nullptr || k <= 1) {
        return;
    }
    Node* currentptr = list.head;
    Node* prevGroupEnd = nullptr;  
    bool firstPass = true;         

    while (currentptr != nullptr) {
        Node* check = currentptr;
        int count = 0;
        while (count < k && check != nullptr) {
            check = check->next;
            count++;
        }

        if (count < k) {
            break; 
        }

        Node* groupStart = currentptr;
        Node* prev = nullptr;
        for (int i = 0; i < k; i++) {
            Node* next = currentptr->next;
            currentptr->next = prev;
            prev = currentptr;
            currentptr = next;
        }

        if (firstPass) {
            list.head = prev;
            firstPass = false;
        } 
        else {
            prevGroupEnd->next = prev;
        }

        groupStart->next = currentptr;
        prevGroupEnd = groupStart; 
    }

    list.tail = list.head;
    while (list.tail != nullptr && list.tail->next != nullptr) {
        list.tail = list.tail->next;
    }
}


int main() {
    singlyLL ll;
    ll.pushBack(1);
    ll.pushBack(2);
    ll.pushBack(3);
    ll.pushBack(4);
    ll.pushBack(5);
    ll.pushBack(6);
    ll.pushBack(7);
    ll.pushBack(8);
    ll.pushBack(9);
    ll.pushBack(10);
    ll.pushBack(11);
    ll.print();
    reverse(ll, 3);
    ll.print();
}
