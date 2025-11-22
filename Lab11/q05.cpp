/* Implement a C++ class StudentHashTable to manage student records in a hash table with a size of 15. Use quadratic probing for collision resolution with the formula (index + attempt^2) % table size.Implement the function InsertRecord that takes a student's roll number and name, inserting the record into the hash table using quadratic probing.Implement the function SearchRecord that takes a roll number, searches for the corresponding record using quadratic probing, and prints the student's name if found; otherwise, print a "Record not found" message. */

#include <iostream>
#include <string>
using namespace std;

class StudentRecord {
public:
    int rollNo;
    string studentName;
    StudentRecord(int id, string n) : rollNo(id), studentName(n) {}
};

class StudentHashTable {
    StudentRecord** records;
    int capacity;
    int calculateHash(int id) { return id % capacity; }
public:
    StudentHashTable(int maxSize = 15) : capacity(maxSize) {
        records = new StudentRecord*[capacity];
        for (int i = 0; i < capacity; i++) { records[i] = NULL; }
    }
    
    void addStudent(int id, string name) {
        int i = calculateHash(id);
        int probeNo = 0;
        while (probeNo < capacity) {
            int currentIndex = (i + probeNo * probeNo) % capacity;
            if (records[currentIndex] == NULL) {
                records[currentIndex] = new StudentRecord(id, name);
                return;
            }
            probeNo++;
        }
        cout << "is full" << endl;
    }
    
    void SearchRecord(int id) {
        int initialIndex = calculateHash(id);
        int probeAttempt = 0;
        
        while (probeAttempt < capacity) {
            int checkIndex = (initialIndex + probeAttempt * probeAttempt) % capacity;
            if (records[checkIndex] == NULL) {
                cout << "not found" << endl;
                return;
            }
            if (records[checkIndex]->rollNo == id) {
                cout << "Student Name: " << records[checkIndex]->studentName << endl;
                return;
            }
            probeAttempt++;
        }
        cout << "not found" << endl;
    }
};

int main() {
    StudentHashTable table;
    table.addStudent(101, "shrek");
    table.addStudent(116, "fiona");
    table.addStudent(131, "donkey");
    table.SearchRecord(131);
    table.SearchRecord(999);
}
