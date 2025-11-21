/*Task # 1
Suppose you are working on a program that needs to store a large number of strings, with the possibility of
duplicate strings. You decide to use chain hashing to efficiently store and retrieve the strings, but you want
to ensure that collisions are avoided as much as possible. Your hash function simply takes the sum of the
ASCII values of the characters in the string and returns the remainder after dividing by the number of
buckets. You decide to implement the hash table using a linked list for each bucket.*/
#include <iostream>
#include <string>
using namespace std;

struct Node {
    string key;
    string value;
    Node* next;
    Node(string k, string v) : key(k), value(v), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;
public:
    LinkedList() : head(nullptr) {}
    
    void insert(string key, string value) {
        Node* current = head;
        while (current != nullptr) {
            if (current->key == key) {
                current->value = value;
                return;
            }
            current = current->next;
        }
        Node* newNode = new Node(key, value);
        newNode->next = head;
        head = newNode;
    }
    
    string search(string key) {
        Node* current = head;
        while (current != nullptr) {
            if (current->key == key) {
                return current->value;
            }
            current = current->next;
        }
        return ""; 
    }
    
    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << "[" << current->key << ": " << current->value << "]";
            if (current->next != nullptr) {
                cout << " -> ";
            }
            current = current->next;
        }
    }
    
    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
};

class HashTable {
private:
    LinkedList* table;
    int capacity;
    int hashFunction(string key) {
        int sum = 0;
        for (char c : key) {
            sum += (int)c; 
        }
        return sum % capacity; 
    }
public:
    HashTable(int size = 10) {
        capacity = size;
        table = new LinkedList[capacity];
    }
    
    void insert(string key, string value) {
        int index = hashFunction(key);
        cout << "Inserting '" << key << "' at " << index << endl;
        table[index].insert(key, value);
    }
    
    string search(string key) {
        int index = hashFunction(key);
        return table[index].search(key);
    }
    
    void display() {
        for (int i = 0; i < capacity; i++) {
            cout << "Bucket " << i << ": ";
            table[i].display();
            cout << endl;
        }
    }
    
    void displayBucket(string key) {
        int index = hashFunction(key);
        cout << "Bucket " << index << " (for key '" << key << "'): ";
        table[index].display();
        cout << endl;
    }
    
    ~HashTable() {
        delete[] table;
    }
};

int main() {
    HashTable myhash(5);
    myhash.insert("A", "aaaaa");
    myhash.insert("B", "bbbbb");
    myhash.insert("C", "ccccc");
    myhash.insert("A", "zzzzz"); 
    myhash.display();
    cout << "Key 'A': " << myhash.search("A") << endl;
    cout << "Key 'B': " << myhash.search("B") << endl;
    cout << "Key 'C': " << myhash.search("C") << endl;
    cout << "Key 'D': " << myhash.search("D") << endl;
    myhash.displayBucket("A");
    myhash.displayBucket("B");
    myhash.displayBucket("C");
}
