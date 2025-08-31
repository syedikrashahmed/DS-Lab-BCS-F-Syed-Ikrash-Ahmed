/*Implement a program to represent a sparse matrix using a dynamic 2D array.
=> Input matrix elements.
=> Display the matrix in normal form.
=> Display the matrix in compressed form (row, column, value).*/

#include <iostream>
using namespace std; 

class Matrix {
    int row;
    int col;
    int **cells;

    public:
    Matrix() : row(0), col(0), cells(nullptr)  {}

    Matrix(int row, int col) : row(row), col(col) {
        int val;
        cells = new int*[row];
        for (int i =0; i < row; i++) {
            cells[i] = new int[col];
            for (int j = 0; j < col; j++) {
                cout << "Enter element ["<<i<<"]["<<j<<"]: ";
                cin >> cells[i][j];
            }
        }
    }

    void displayNormalForm  () {
        cout << "printing matrix in normal Form:"<<endl;
        for (int i =0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                cout << " " << cells[i][j] << " ";
            }
            cout<< endl;
        }
    }

    void displayCompressedForm() {
        cout << "printing matrix in compressed Form:"<<endl;
        int numNonZeroes = 0;
        for (int i =0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (cells[i][j] != 0) {
                    numNonZeroes++;
                }
            }
        }

        int* data = new int[numNonZeroes];
        int* cRows = new int[numNonZeroes];
        int* cCols = new int[numNonZeroes];
        int index = 0;
        for (int i =0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (cells[i][j] != 0) {
                    data[index] = cells[i][j];  
                    cRows[index] = i;
                    cCols[index] = j;
                    index++;
                }
            }
        }
        cout << "data: {";
        for (int i = 0; i < numNonZeroes; i++) {
            cout << data[i] <<", ";
        }
        cout << "}" <<endl << "rows: {";
        for (int i = 0; i < numNonZeroes; i++) {
            cout << cRows[i] <<", ";
        }
        cout << "}" <<endl << "cols: {";
        for (int i = 0; i < numNonZeroes; i++) {
            cout << cCols[i] <<", ";
        }
        cout << "}" <<endl;
    }

    ~Matrix() {
        for (int i =0; i < row; i++) {
            delete [] cells[i];
        }
        delete []cells;
    }
};

int main() {
    int r, c;
    cout << "Enter rows: ";
    cin >> r;
    cout << "Enter cols: ";
    cin >> c;
    Matrix m(r,c);
    m.displayNormalForm();
    m.displayCompressedForm();
}
