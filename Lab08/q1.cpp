/*Question#1:Implement a binary search tree and perform all operations you learned above like:Inserting, Deleting, Searching, and Traversing.*/

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

Node* minNode(Node* root) {
        while (root->left != nullptr) {
            root = root->left;
        }
        return root;
 }

Node* deleteNode(Node* root, int val) { 
        if (root == nullptr) {
            cout << "not found" << endl;
            return root;
        }
        else if (val < root->data) {
            root->left = deleteNode(root->left, val);
        }
        else if (val > root->data) {
            root->right = deleteNode(root->right, val);
        }
        else { 
            if (root->left == nullptr) {
                Node* temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == nullptr) {
                Node* temp = root->left;
                delete root;
                return temp;
            }
            else {
                Node* temp = minNode(root->right);
                root->data = temp->data;
                root->right = deleteNode(root->right, temp->data);             
            }
        }
        return root;
}

void inOrder(Node* root) {
    if (root == nullptr) {
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void preOrder(Node* root) {
    if (root == nullptr) {
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node* root) {
    if (root == nullptr) {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

int main() {
 int arr[6] = {3, 2, 1, 5, 6, 4};
 Node* root = nullptr;
 for (int i = 0; i< 6; i++) {
 	root = insert(root, arr[i]);
 }
 
 inOrder(root);
 cout <<endl;
 preOrder(root); 
 cout << endl;
 postOrder(root);
 cout<< endl;
 if (search(root, 9)) {
     cout << "FOUND" << endl;
 } else {
     cout << "NOT FOUND" << endl;
 }
 Node* newRoot = deleteNode(root, 5);
 cout << "newRoot: "<< newRoot->data << endl;
 inOrder(root);
 cout <<endl;
 preOrder(root); 
 cout << endl;
 postOrder(root);
 cout<< endl;
 
}