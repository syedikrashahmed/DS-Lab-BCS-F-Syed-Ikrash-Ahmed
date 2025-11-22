/*Task # 3: Implement the class Hash class having the functionality of insert, delete, search and display using list (built in library for linked list in C++).*/
#include <iostream>
#include <string>
#include <list>
using namespace std;

class Hash {
private:
    int size;
    list<pair<int, string>>* table;
    
    int hashFunction(int key) {
        return key % size;
    }

public:
    Hash(int size = 10) : size(size) {
        table = new list<pair<int, string>>[size];
    }
    
    ~Hash() {
        delete[] table;
    }
    
    void insert(int key, string value) {
        int index = hashFunction(key);
        list<pair<int, string>> tempList = table[index];
        while (!tempList.empty()) {
            if (tempList.front().first == key) {
                table[index].clear();
                list<pair<int, string>> newList;
                while (!tempList.empty()) {
                    pair<int, string> current = tempList.front();
                    tempList.pop_front();

                    if (current.first == key) {
                        newList.push_back(make_pair(key, value));
                    } 
                    
                    else {
                        newList.push_back(current);
                    }
                }
                table[index] = newList;
                cout << "key " << key << " updated" << endl;
                return;
            }
            tempList.pop_front();
        }
        table[index].push_back(make_pair(key, value));
        cout << "key " << key << " inserted"<< endl;
    }
    
    void remove(int key) {
        int index = hashFunction(key);
        if (table[index].empty()) {
            cout << "key " << key << " not found" << endl;
            return;
        }
        
        list<pair<int, string>> tempList = table[index];
        list<pair<int, string>> newList;
        bool found = false;
        while (!tempList.empty()) {
            pair<int, string> current = tempList.front();
            tempList.pop_front();

            if (current.first == key) {
                found = true;
            } 

            else {
                newList.push_back(current);
            }
        }
        table[index] = newList;
        
        if (found) {
            cout << "key " << key << " deleted" << endl;
        } 
        else {
            cout << "key " << key << " not found" << endl;
        }
    }
    
    void search(int key) {
        int index = hashFunction(key);
        list<pair<int, string>> tempList = table[index];
        while (!tempList.empty()) {
            if (tempList.front().first == key) {
                cout << "key " << key << " found with value: " << tempList.front().second << endl;
                return;
            }
            tempList.pop_front();
        }
        cout << "key " << key << " not found." << endl;
    }
    
    void display() {
        for (int i = 0; i < size; i++) {
            cout << "index " << i << ": ";
            if (table[i].empty()) {
                cout << "empty";
            } 
            
            else {
                list<pair<int, string>> tempList = table[i];
                while (!tempList.empty()) {
                    cout << "(" << tempList.front().first << "," << tempList.front().second << ") ";
                    tempList.pop_front();
                }
            }
            cout << endl;
        }
    }
};

int main() {
    Hash hashTable(7);
    hashTable.insert(56, "babar azam");
    hashTable.insert(10, "shaheen afridi");
    hashTable.insert(16, "mhd rizwan");
    hashTable.insert(63, "saim ayub");
    hashTable.insert(39, "fakhar zaman");
    hashTable.insert(7, "shadab khan");
    hashTable.insert(71, "naseem shah");
    hashTable.search(56);
    hashTable.display();
    hashTable.remove(10);
    hashTable.display();
}
