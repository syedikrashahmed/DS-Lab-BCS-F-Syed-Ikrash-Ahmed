/*Task 5:Implement Quick Sort using linked list in C++. Define a node for a linked list with integer data anda pointer to the next node. Write a function to swap two nodes in the linked list. Write a function topartition the linked list using the last node as the pivot. Implement the Quick Sort algorithm usingthe partition function and the swap function. Finally, write a function to print the sorted linked list.Your implementation should be able to handle empty linked lists and linked lists with only one node.Test your implementation with a sample linked list containing the following integers: 10, 7, 8, 9, 1,5, 3. The expected output after sorting should be: 1 3 5 7 8 9 10.*/

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void append(Node*& head, int new_data) {
    Node* new_node = new Node{new_data, nullptr};
    if (head == nullptr) {
        head = new_node;
        return;
    }
    Node* temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = new_node;
}

void swap(Node* a, Node* b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

Node* partition(Node* head, Node* end, Node*& newHead, Node*& newEnd) {
    Node* pivot = end;
    Node* prev = nullptr;
    Node* cur = head;
    Node* tail = pivot;

    newHead = nullptr;
    newEnd = nullptr;

    while (cur != pivot) {
        if (cur->data < pivot->data) {
            if (newHead == nullptr)
                newHead = cur;
            prev = cur;
            cur = cur->next;
        } else {
            if (prev)
                prev->next = cur->next;

            Node* tmp = cur->next;
            cur->next = nullptr;
            tail->next = cur;
            tail = cur;
            cur = tmp;
        }
    }

    if (newHead == nullptr)
        newHead = pivot;
    newEnd = tail;
    return pivot;
}

Node* quickSortRecur(Node* head, Node* end) {
    if (!head || head == end)
        return head;

    Node* newHead = nullptr;
    Node* newEnd = nullptr;
    Node* pivot = partition(head, end, newHead, newEnd);

    if (newHead != pivot) {
        Node* temp = newHead;
        while (temp->next != pivot)
            temp = temp->next;

        temp->next = nullptr;
        newHead = quickSortRecur(newHead, temp);
        Node* tail = newHead;
        while (tail->next)
            tail = tail->next;
        tail->next = pivot;
    }

    pivot->next = quickSortRecur(pivot->next, newEnd);
    return newHead;
}

Node* getTail(Node* head) {
    while (head && head->next)
        head = head->next;
    return head;
}

void quickSort(Node*& head) {
    Node* end = getTail(head);
    head = quickSortRecur(head, end);
}

void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;
    int arr[] = {10, 7, 8, 9, 1, 5, 3};
    int n = 7;
    for (int i = 0; i < n; i++)
        append(head, arr[i]);

    printList(head);
    quickSort(head);
    printList(head);
}