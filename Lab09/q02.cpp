/*Task#2: Suppose you have an AVL tree with the following elements: 50, 30, 70, 20, 40, 60, 80.
You need to insert a new node with value 55 into the tree and then display the tree after
performing a left rotation on the root. Write a C++ code to accomplish this task using the
AVLTree class and its methods.*/

#include <iostream>
using namespace std;
#include <string>

int max(int a, int b) {
    if (a > b) { 
        return a;
    }
    return b;
}

struct Node {
    int key;
    Node* left;
    Node* right;
    int height;
    Node(int val) : key(val), left(nullptr), right(nullptr), height(1) {}
};

class AVLTree {
    public:
    Node* root;

    AVLTree() {
        root = nullptr;
    }

    int getHeight(Node* node) {
        if (node == nullptr) { 
            return 0;
        }
        return node->height;
    }
    
    int getBalance(Node* node) {
        if (node == nullptr) { 
            return 0; 
        }
        return getHeight(node->left) - getHeight(node->right);
    }
    
    Node* rightRotate(Node* node) {
        Node* x = node->left;
        Node* temp = x->right;
        x->right = node;
        node->left = temp;
        node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
        return x;
    }
    
    Node* leftRotate(Node* x) {
        Node* node = x->right;
        Node* temp = node->left;
        node->left = x;
        x->right = temp;
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
        node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
        return node;
    }
    
    Node* insert(Node* node, int key) {
        if (node == nullptr) {
            return new Node(key);
        }

        if (key < node->key) {
            node->left = insert(node->left, key);
        }

        else if (key > node->key) {
            node->right = insert(node->right, key);
        }

        else {
            return node;
        }

        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
        int balance = getBalance(node);
        
        // Left Left
        if (balance > 1 && key < node->left->key)
            return rightRotate(node);
            
        // Right Right
        if (balance < -1 && key > node->right->key)
            return leftRotate(node);
            
        // Left Right
        if (balance > 1 && key > node->left->key) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        
        // Right Left
        if (balance < -1 && key < node->right->key) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
        return node;
    }
    
    void inorder(Node* node) {
        if (node != nullptr) {
            inorder(node->left);
            cout << node->key << " ";
            inorder(node->right);
        }
    }
};

int main() { //50, 30, 70, 20, 40, 60, 80.
    AVLTree tree;
    tree.root = tree.insert(tree.root, 50);
    tree.root = tree.insert(tree.root, 30);
    tree.root = tree.insert(tree.root, 70);
    tree.root = tree.insert(tree.root, 20);
    tree.root = tree.insert(tree.root, 40);
    tree.root = tree.insert(tree.root, 60);
    tree.root = tree.insert(tree.root, 80);
    tree.inorder(tree.root);
    cout << endl;   
    tree.root = tree.insert(tree.root, 55);
    tree.inorder(tree.root);
    cout << endl;
    tree.root = tree.leftRotate(tree.root);
    tree.inorder(tree.root);
    cout << endl;
}
