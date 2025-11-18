/*Question#4: Search for the value defined by the user in the tree. If the value does not
exist insert it and print the new tree.*/

#include <iostream>
using namespace std;
#include <string>

class Node {
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int val) {
    if (root == nullptr) {
        return new Node(val);
    }
    if (root->data > val) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    return root;
}

bool search(Node* root, int target) {
    if (root == nullptr) {
        return false;
    }

    if (root->data == target) {
        return true;
    }

    if (root->data > target) {
        return search(root->left, target);
    }
    else {
         return search(root->right, target);
    }
}

void preOrder(Node* root) {
    if (root == nullptr) {
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

int main() {
 int arr[6] = {3, 2, 1, 5, 6, 4};
 Node* root = nullptr;
 for (int i = 0; i< 6; i++) {
 	root = insert(root, arr[i]);
 }
 
 preOrder(root);
 cout << endl;

int val = 9;
 if (search(root, val)) {
     cout << "FOUND" << endl;
 } 
 else {
     cout << "NOT FOUND, inserting " << val << endl;
     root = insert(root, val);
     preOrder(root);
 }
}