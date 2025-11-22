/*Task # 2:
Some ABC university students want to develop an ASCII code-based dictionary app for their Final Year
Project. This app should allow the users to perform the following operations:
a) Add_Record () This function will take a string input from user and add into the dictionary. For adding
the string user will use a unique hash function k MOD 100 (table size must be 100, for k user will calculate
the SUM of ASCII character of that word).
b) Word_Search () User will only pass a single string. If string is not available then generate an error
message.
c) Print_Dictionary () Users can also display the complete dictionary.*/
#include <iostream>
#include <string>
using namespace std;
struct HashNode {
    string identifier;
    string data;
    HashNode* nextNode;
    HashNode(string id, string val) : identifier(id), data(val), nextNode(nullptr) {}
};

class DictionaryHash {
private:
    HashNode* hashTable[100];
    int getHashIndex(string id) {
        int asciiSum = 0;
        for (int i = 0; i < id.length(); i++) {
            asciiSum += (int)id[i];
        }
        return asciiSum % 100;
    }
public:
    DictionaryHash() {
        for (int i = 0; i < 100; i++) {
            hashTable[i] = nullptr;
        }
    }
    
    void Add_Record(string id, string val) {
        int tableIndex = getHashIndex(id);
        HashNode* newNode = new HashNode(id, val);

        HashNode* temp = hashTable[tableIndex];
         while (temp != nullptr) {  
            if (temp->identifier == id) {
                cout << "Key " << id << " already exists. Updating value." << endl;
                temp->data = val;
                return;
            }
            temp = temp->nextNode;
        }
        
        newNode->nextNode = hashTable[tableIndex];
        hashTable[tableIndex] = newNode;
    }
    
    void Word_Search(string id) {
        int tableIndex = getHashIndex(id);
        HashNode* currentNode = hashTable[tableIndex];
        
        while (currentNode != nullptr) {
            if (currentNode->identifier == id) {
                cout << "search key " << id << ": " << currentNode->data << endl;
                return;
            }
            currentNode = currentNode->nextNode;
        }
        cout << "Key " << id << " not found!" << endl;
    }
    
    void removeKey(string id) {
        int tableIndex = getHashIndex(id);
        HashNode* currentNode = hashTable[tableIndex];
        HashNode* previousNode = nullptr;
        
        while (currentNode != nullptr) {
            if (currentNode->identifier == id) {
                if (previousNode == nullptr) {
                    hashTable[tableIndex] = currentNode->nextNode;
                } else {
                    previousNode->nextNode = currentNode->nextNode;
                }
                delete currentNode;
                cout << "key " << id << " deleted successfully !" << endl;
                return;
            }
            previousNode = currentNode;
            currentNode = currentNode->nextNode;
        }
        cout << "Key " << id << " not found for deletion!" << endl;
    }
    
    void Print_Dictionary(int bucketIndex) {
        if (bucketIndex < 0 || bucketIndex >= 100) {
            cout << "Invalid bucket index!" << endl;
            return;
        }
        
        cout << "index " << bucketIndex << ": ";
        HashNode* currentNode = hashTable[bucketIndex];
        bool isFirstEntry = true;
        
        while (currentNode != nullptr) {
            if (!isFirstEntry) {
                cout << " -> ";
            }
            cout << "(" << currentNode->identifier << ", " << currentNode->data << ")";
            isFirstEntry = false;
            currentNode = currentNode->nextNode;
        }
        
        if (isFirstEntry) {
            cout << "empty";
        }
        cout << endl;
    }
    
    ~DictionaryHash() {
        for (int i = 0; i < 100; i++) {
            HashNode* currentNode = hashTable[i];
            while (currentNode != nullptr) {
                HashNode* tempNode = currentNode;
                currentNode = currentNode->nextNode;
                delete tempNode;
            }
        }
    }
};

int main() {
    DictionaryHash myDict;
    myDict.Add_Record("AB", "FASTNU");
    myDict.Add_Record("CD", "CS");
    myDict.Add_Record("EF", "ikrash");
    myDict.Word_Search("AB");
    myDict.removeKey("EF");
    myDict.Print_Dictionary(31);
    myDict.Print_Dictionary(35);
}
