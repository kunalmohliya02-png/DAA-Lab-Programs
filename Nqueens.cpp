// Program 5: Solve the N-Queens problem using Backtracking

#include <iostream>
#include <vector>
using namespace std;

void printBoard(vector<vector<int>>& board, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j])
                cout << "Q ";
            else
                cout << ". ";
        }
        cout << "\n";
    }
}

bool isSafe(vector<vector<int>>& board, int row, int col, int N) {
    // Check this row on left side
    for (int i = 0; i < col; i++)
        if (board[row][i]) return false;

    // Check upper diagonal on left side
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j]) return false;

    // Check lower diagonal on left side
    for (int i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j]) return false;

    return true;
}

bool solveNQUtil(vector<vector<int>>& board, int col, int N) {
    // Base case: If all queens are placed
    if (col >= N) return true;

    // Try placing this queen in all rows one by one
    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col, N)) {
            board[i][col] = 1; // Place Queen

            // Recur to place rest of the queens
            if (solveNQUtil(board, col + 1, N))
                return true;

            // Backtrack: remove queen if placing doesn't lead to a solution
            board[i][col] = 0;
        }
    }
    return false;
}

int main() {
    int N = 4;
    vector<vector<int>> board(N, vector<int>(N, 0));

    cout << "Solving N-Queens for N = " << N << ":\n\n";
    if (solveNQUtil(board, 0, N)) {
        printBoard(board, N);
    } else {
        cout << "Solution does not exist\n";
    }

    return 0;
}

/* --- OUTPUT ---
Solving N-Queens for N = 4:

. . Q . 
Q . . . 
. . . Q 
. Q . . 
*/
