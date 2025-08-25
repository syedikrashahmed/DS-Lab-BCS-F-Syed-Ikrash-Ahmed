/* Q2. Create a C++ class named "Exam" using DMA designed to manage student exam records,
 complete with a shallow copy implementation? Define attributes such as student name, exam
 date, and score within the class, and include methods to set these attributes and display exam
 details. As part of this exercise, intentionally omit the implementation of the copy constructor
 and copy assignment operator. Afterward, create an instance of the "Exam" class, generate a
 shallow copy, and observe any resulting issues?*/

#include <iostream>
#include <string.h>
using namespace std;

class Exam {
    private:
    char* studentName;
    char* examDate;
    float score;

    public:
    Exam() {
        studentName = new char[2];
        strcpy(studentName, " ");
        examDate = new char[2];
        strcpy(examDate, " ");
        score = 0.0;
    }
    Exam(const char* name, const char* date, float sco) {
        studentName = new char[strlen(name) + 1];
        strcpy(studentName, name);
        examDate = new char[strlen(date) + 1];
        strcpy(examDate, date);
        score = sco;
    }
    ~Exam() {
        delete[] studentName;
        delete[] examDate;
    }
    void setName(const char* name) { strcpy(studentName, name); }
    void setDate(const char* date) { strcpy(studentName, date); }
    void setScore(float score) { this->score = score; }
    void print() {
        cout << "Name:" << studentName <<", Score:" << score << ", Exam Date:" <<examDate << endl;
    }
};

int main() {
    Exam e1("ikrash", "010196", 30.7);
    e1.print();
    Exam e2(e1);
    e2.print();
    e2.setName("babar");
    e2.print();
    e1.print();
    /*
    here the error as we can see if that, as it was a shallow copy the pointer of student name wasnt copied properly, becuase of which even after we changed the name in e2, it changed in e1 as well
    */
}