/*4. Josephus Problem using Circular Linked List
Use a circular linked list to solve the Josephus problem:
• N people stand in a circle, eliminating every k-th person until only one survives.
• Input: N = 7, k = 3
• Output: Position of survivor.
• Hint: Use circular traversal and deletion.*/
#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class CircularLL {
    public:
    Node* head;

    CircularLL() : head(nullptr) {}

    void pushBack(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            newNode->next = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void print() {
        if (head == nullptr) {
            cout << "List empty" << endl;
            return;
        }

        Node* temp = head;
        while (temp->next != head) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << temp->data << endl;
    } 
};

void deleteKth(Node* head, int k) {
        if (head == nullptr) {
            cout << "list empty"<<endl;
            return;
        }

        if (head == head->next) {
            cout << "winner is "<< head->data<< endl;
            return;
        }

        Node* temp = head;
        // Node* toDelete = temp->next->next;
        Node* toDelete = head;
        for (int i = 1; i < k; i++) {
            toDelete = toDelete->next;
        }
        for (int i = 1; i < k - 1; i++) {
            temp = temp->next;
        } 
        temp->next = toDelete->next;
        delete toDelete;
        temp = temp->next;
        deleteKth(temp, k);
}

int main() {
    CircularLL list;
    list.pushBack(1);
    list.pushBack(2);
    list.pushBack(3);
    list.pushBack(4);
    list.pushBack(5);
    list.pushBack(6);
    list.pushBack(7);
    list.print();
    deleteKth(list.head, 3);
}
