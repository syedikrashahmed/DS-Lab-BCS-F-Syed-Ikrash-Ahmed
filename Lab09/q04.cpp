/*Task#4: Find the kth smallest and largest value in the AVL tree and print its key also print both
the left side and right side height of the tree starting from root.*/

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
    
    void kthSmallestUtil(Node* node, int& k, int& count, int& result) {
        if (node == nullptr || count >= k) {
            return;
        }

        kthSmallestUtil(node->left, k, count, result);  
        count++;
        if (count == k) {
            result = node->key;
            return;
        } 
        kthSmallestUtil(node->right, k, count, result);
    }
    
    void kthLargestUtil(Node* node, int& k, int& count, int& result) {
        if (node == nullptr || count >= k) {
            return;
        }

        kthLargestUtil(node->right, k, count, result);
        count++;
        if (count == k) {
            result = node->key;
            return;
        }
        kthLargestUtil(node->left, k, count, result);
    }
};

int main() {
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
    
    int leftHeight = tree.getHeight(tree.root->left);
    int rightHeight = tree.getHeight(tree.root->right);
    cout << "Left subtree height: " << leftHeight << endl;
    cout << "Right subtree height: " << rightHeight << endl;

    int k = 3, ksmall = -1, count = 0, klarge = -1;
    tree.kthSmallestUtil(tree.root, k, count, ksmall);
    count =0;
    tree.kthLargestUtil(tree.root, k, count, klarge);
    cout << k << " smallest value: " << ksmall << endl;
    cout << k << " largest value: " << klarge << endl;
}
