/*Task #5:
Write a C++ program that dynamically creates a 2D matrix and provides:
=> Addition of two matrices.
=> Subtraction of two matrices.
=> Ensure safe memory handling with proper allocation/deallocation.*/

#include <iostream>
using namespace std;

int** add(int** m1, int** m2, int r, int c) {
    int** newM = new int*[r]; 
    for (int i = 0; i < r; i++){
        newM[i] = new int[c];
    }

    for (int i = 0; i < r; i++){
        for(int j =0; j< c;j++) {
            newM[i][j] = m1[i][j] + m2[i][j];
        }
    }
    return newM;
}

int** subtract(int** m1, int** m2, int r, int c) {
    int** newM = new int*[r]; 
    for (int i = 0; i < r; i++){
        newM[i] = new int[c];
    }

    for (int i = 0; i < r; i++){
        for(int j =0; j< c;j++) {
            newM[i][j] = m1[i][j] - m2[i][j];
        }
    }
    return newM;
}

void print(int** m, int r, int c) {
    for (int i =0; i<r; i++) {
        for(int j =0; j< c;j++){
            cout << m[i][j] << ", ";
        }
        cout <<endl;
    }
}

int main (){
    int row,col;
    cout << "rows for matrix : ";
    cin >> row;
    cout << "cols for matrix: ";
    cin >> col;

    int **m1, **m2;
    m1 = new int*[row]; m2 = new int*[row];

    for (int i = 0; i < row; i++) {
        m1[i] = new int[col];
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << "enetr for matric 1 [" << i << "][" <<j<< "]:";
            cin >> m1[i][j];
        }
    }

    for (int i = 0; i < row; i++) {
        m2[i] = new int[col];
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << "enetr for matric 2 [" << i << "][" <<j<< "]:";
            cin >> m2[i][j];
        }
    }

    cout << "Matre 1:" << endl;
    print(m1, row, col);
    cout << "Matre 2:" << endl;
    print(m2, row, col);
    int** addm = add(m1, m2, row, col);
    cout << "add:" << endl;
    print(addm, row, col);
    int** subm = subtract(m1, m2, row, col);
    cout << "subtrat:" << endl;
    print(subm, row, col);

    for (int i=0; i<row; i++) {
        delete[] m1[i];
        delete[] m2[i];
        delete[] addm[i];
        delete[] subm[i];
    }
    delete[] m1;
    delete[] m2;
    delete[] addm;
    delete[] subm;
}
