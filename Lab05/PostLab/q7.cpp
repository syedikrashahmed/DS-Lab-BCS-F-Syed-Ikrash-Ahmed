/*Task 7:
Create a program that solves the N-Queens problem for any given N using backtracking. The program should print all possible solutions for placing N queens on an N x N chessboard so that no two queens threaten each other. This task requires you to use a recursive function to place queens row by row , and a validation function to check if a queen can be placed in a specific cell. If a placement leads to a conflict, the algorithm should backtrack to the previous row and try a different column.*/

#include <iostream>
using namespace std;
    
bool isSafe (char** board, int row, int col, int n) {
    //vertical
    for (int i = 0; i < n; i++){
        if(board[row][i] == 'Q') {
            return false;
        }
    }

    //horizontal
    for (int i = 0; i < n; i++)  {
        if (board[i][col] == 'Q'){
            return false;
         }
  }
    
    //left diagnol
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--){
        if(board[i][j] == 'Q')  {
            return false;
        }
    }
    
    //right diagnol
    for (int i = row, j = col; i >= 0 && j < n; i--, j++)  {
        if (board[i][j] == 'Q'){
            return false;
         } 
    }

    return true;
}

void nQueens (char** board, int row, int n, char** answer) {
    if (row == n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                answer[i][j] = board[i][j]; 
            }
        }
        return;
    }

    for (int i = 0; i < n; i++) {
        if (isSafe(board, row, i, n)) {
            board[row][i] = 'Q';
            nQueens(board, row + 1, n, answer);
            board[row][i] = '.';
        }
    }
}

int main() {
    int n; 
    cout << "Enter N: ";
    cin >> n;
    char **arr = new char *[n];
    char **sol = new char *[n];
    for (char i = 0; i < n; i++) {
        arr[i] = new char[n];
        sol[i] = new char[n];
    }

    for (char i = 0; i < n; i++) {
        for (char j = 0; j < n; j++) {
            arr[i][j] = '.';
        }
    }
    
    nQueens(arr, 0, n, sol);
    for (char i = 0; i < n; i++) {
        for (char j = 0; j < n; j++) {
            cout << sol[i][j]<< " ";
        }
        cout << endl;
    }
}
