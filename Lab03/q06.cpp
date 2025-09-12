/*6. Flatten a Multilevel Linked List
Each node has:
• next pointer (normal linked list connection).
• child pointer (points to another linked list).
Write a function to flatten the structure so that all nodes appear in a single-level list.
• Example:
• 1 → 2 → 3
• |
• 4 → 5
Output: 1 → 2 → 4 → 5 → 3*/

#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node* child;

    Node(int data) : data(data), next(nullptr), child(nullptr) {}
};

class MultilevelLL {
    public:
    Node* head;
    Node* tail;
 
    MultilevelLL() : head(nullptr), tail(nullptr) {}

    void pushBack(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = tail = newNode;
            return;
        }
        
        tail->next = newNode;
        tail = newNode;
    }

    void addChild(int cVal, int pVal) {
        if (head == nullptr) {
            return;
        }
        Node* temp = head;
        while(temp != nullptr && temp->data != pVal) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "invalid parent" << endl;
            return;
        }

        Node* newNode = new Node(cVal);
        if (temp->child == nullptr) {
            temp->child = newNode;
        }
        else {
            Node* temp2 = temp->child;
            while (temp2->next != nullptr) {
                temp2 = temp2->next;
            }
            temp2->next = newNode;
        }
    }

    void print(Node* head) {
        if (head == nullptr) {
            cout << "List empty" << endl;
            return;
        }
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->child != nullptr) {
                cout << temp->data << " ";
                print(temp->child);
                temp = temp->next;
            }
            else {
                cout << temp->data << " ";
                temp = temp->next;
            }
        }
    }

    Node* flattenList(Node* head) {
        if (head == nullptr) {
            return nullptr;
        }
        Node* currentptr = head;
        while (currentptr != nullptr) {
            if (currentptr->child != nullptr) {
                Node* next = currentptr->next;
                currentptr->next = flattenList(currentptr->child);
                currentptr->child = nullptr;

                while (currentptr->next != nullptr) {
                    currentptr = currentptr->next;
                }
                 
                if (next != nullptr) {
                    currentptr->next = next;
                }           
            }
            currentptr = currentptr->next;
        }
        return head;
    }

    ~MultilevelLL() {
        flattenList(head);
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

int main() {
    MultilevelLL list;
    list.pushBack(1);
    list.pushBack(2);
    list.pushBack(3);
    list.addChild(4,2);
    list.addChild(5,2);
    list.print(list.head);
    cout<<endl;
    list.head = list.flattenList( list.head);
    list.print(list.head);
}
