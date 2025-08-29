/*Task #10:
Design a program that maintains library book records using dynamic arrays.
=> Each row represents a category (e.g., Fiction, Science, History).
=> Each category has a different number of books (use a jagged array).
=> Store book IDs dynamically and allow the user to search for a given book ID.
=> Print whether the book is available and in which category.*/

#include <iostream>
using namespace std;

int main() {
    int numCateg; int* numids;
    cout << "Enter num of categories:";
    cin>> numCateg;
    string *categories = new string[numCateg];
    numids = new int[numCateg];
    for (int i = 0; i < numCateg;i++) {
        cout << "enter category " << i +1<< ":";
        cin>> categories[i];
        cout << "Enter num books in " << categories[i] << ":";
        cin >>numids[i];
    } 

    int **ids = new int*[numCateg];
    for (int  i = 0; i < numCateg;i++) {
        ids[i] = new int[numids[i]];
    }

    for (int  i = 0; i < numCateg;i++) {
        for (int j = 0; j<numids[i]; j++) {
            cout << "enter id of book "<< i +1<< "of " << categories[i] << ":";
            cin>> ids[i][j];
        }
    }

    int tosearch;
    cout << "Enter id to search: ";
    cin>> tosearch;
    bool found = false;
    for (int  i = 0; i < numCateg;i++) {
        for (int j = 0; j<numids[i]; j++) {
            if (ids[i][j] == tosearch) {
                cout << "Book is available and is in category: " << categories[i]<< endl;
                found = true;
                break;
            }
        }
    }

    if (!found) {
        cout << "Not found" <<endl;
    }

    for (int i = 0; i < numCateg; i++) {
        delete[] ids[i];
    }
    delete[] ids;
    delete[] categories;
    delete[] numids;
}
