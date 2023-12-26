#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isSafe(vector<string>& board, int row, int col, int n) {
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 'Q') return false;
    }
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'Q') return false;
    }
    for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 'Q') return false;
    }
    return true;
}

void solveNQueens(vector<vector<string>>& res, vector<string>& board, int row, int n) {
    if (row == n) {
        res.push_back(board);
        return;
    }
    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col, n)) {
            board[row][col] = 'Q';
            solveNQueens(res, board, row + 1, n);
            board[row][col] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> res;
    vector<string> board(n, string(n, '.'));
    solveNQueens(res, board, 0, n);
    return res;
}

void printSolution(vector<vector<string>>& solutions) {
    for (int i = 0; i < solutions.size(); i++) {
        cout << "Solution " << i + 1 << ":\n";
        for (int j = 0; j < solutions[i].size(); j++) {
            cout << solutions[i][j] << endl;
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter the value of n (1 <= n <= 9): ";
    cin >> n;

    if (n < 1 || n > 9) {
        cerr << "Invalid input! Please enter a value between 1 and 9." << endl;
        return 1;
    }

    vector<vector<string>> solutions = solveNQueens(n);
    printSolution(solutions);

    return 0;
}