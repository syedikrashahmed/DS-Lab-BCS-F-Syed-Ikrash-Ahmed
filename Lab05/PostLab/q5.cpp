/*Task 5:
Implement a Sudoku solver using the backtracking technique. The program should take a partially filled 9x9 Sudoku grid and fill the empty cells (represented by 0) to solve the puzzle.
Your algorithm should:
1. Find an empty cell.
2. Try placing a number from 1 to 9 in the empty cell.
3. Check if the number is valid in the current row, column, and 3x3 subgrid.
4. If valid, recursively call the function to solve the rest of the puzzle.
5. If the recursive call doesn't lead to a solution, backtrack by resetting the cell to 0 and trying the next number.*/

#include <iostream>
using namespace std;

bool isSafe(int **arr, int row, int col, int number) {
    // horizontal check
    for (int i = 0; i < 9; i++){
        if(arr[row][i] == number){
            return false;
        }
    }

    // vertical check
    for (int i = 0; i < 9; i++){
        if (arr[i][col] == number){
            return false;
        }
    }

    // small square check
    int startrow = (row/3) *3;
    int startcol = (col/3) *3;

    for (int i = startrow; i<= startrow + 2; i++)  {
        for(int j= startcol; j <= startcol + 2;j++)  {
            if (arr[i][j] == number) {
                return false;
            }
        }
    }

    return true;
}

bool SodukoSolver(int **arr, int row, int col)  {
    if (row == 9){
        return true;
    }
    int nextcol = col + 1;
    int nextrow = row;
    if (nextcol == 9) {
        nextrow++;
        nextcol = 0;
    }
    if (arr[row][col] != 0) {
        return SodukoSolver(arr, nextrow, nextcol);
    }

    for (int digit = 1; digit <= 9; digit++){
        if (isSafe(arr, row, col, digit)) {
            arr[row][col] = digit;
            if (SodukoSolver(arr, nextrow, nextcol)) {
                return true;
            }
            arr[row][col] = 0;
        }
    }

    return false;
}

int main() {
    int **arr = new int *[9];
    for (int i = 0; i < 9; i++) {
        arr[i] = new int [9];
    }

    int board[9][9] = { {5, 3, 0, 0, 7, 0, 0, 0, 0},
                         {6, 0, 0, 1, 9, 5, 0, 0, 0},
                         {0, 9, 8, 0, 0, 0, 0, 6, 0},
                         {8, 0, 0, 0, 6, 0, 0, 0, 3},
                         {4, 0, 0, 8, 0, 3, 0, 0, 1},
                         {7, 0, 0, 0, 2, 0, 0, 0, 6},
                         {0, 6, 0, 0, 0, 0, 2, 8, 0},
                         {0, 0, 0, 4, 1, 9, 0, 0, 5},
                         {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            arr[i][j] = board[i][j];
        }
    }

    if (SodukoSolver(arr, 0, 0)) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << arr[i][j] << " ";
            }
            cout <<endl;
        }
    }
    else {
        cout << "cannot be solved";
    }
}
