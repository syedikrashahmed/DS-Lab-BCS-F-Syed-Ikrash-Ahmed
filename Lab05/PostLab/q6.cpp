/*Task 6:
Modify the provided "Rat in a Maze" code to handle a more complex version of the problem.
The rat should now be able to move in four directions (up, down, left, and right) instead of just
two. Your updated code should still use backtracking to find a valid path from the source (0,0) to
the destination (N-1, N-1) while avoiding dead ends.*/

#include <iostream>
using namespace std;

#define N 5   // size

// to print the solution matrix
void printSolution(int sol[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << sol[i][j] << " ";
        cout << endl;
    }
}

// Check if maze[x][y] is safe to visit
bool isSafe(int maze[N][N], int x, int y, int sol[N][N]) {
    return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1 && sol[x][y] == 0);
}

// Backtracking utility for 4 directions
bool solveMazeUtil(int maze[N][N], int x, int y, int sol[N][N]) {
    // WHEN destination is reached
    if (x == N - 1 && y == N - 1) {
        sol[x][y] = 1;
        return true;
    }

    if (isSafe(maze, x, y, sol)) {
        sol[x][y] = 1;

        // Move Right
        if (solveMazeUtil(maze, x, y + 1, sol)) return true;

        // Move Down
        if (solveMazeUtil(maze, x + 1, y, sol)) return true;

        // Move Up
        if (solveMazeUtil(maze, x - 1, y, sol)) return true;

        // Move Left
        if (solveMazeUtil(maze, x, y - 1, sol)) return true;

        // FOR Backtrack
        sol[x][y] = 0;
        return false;
    }

    return false;
}

void solveMaze(int maze[N][N]) {
    int sol[N][N] = {0};

    if (!solveMazeUtil(maze, 0, 0, sol)) {
        cout << "No solution exists\n";
        return;
    }

    cout << "Path found (4 directions):\n";
    printSolution(sol);
}

int main() {
    int maze[N][N] = {
        {1, 0, 0, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 1, 0, 1, 0},
        {1, 1, 1, 1, 0},
        {0, 0, 0, 1, 1}
    };

    solveMaze(maze);
    return 0;
}
