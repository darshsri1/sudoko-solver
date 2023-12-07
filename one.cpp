#include <iostream>
using namespace std;

const int N = 9;


void printBoard(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}


bool isSafe(int board[N][N], int row, int col, int num) {
    
    for (int i = 0; i < N; i++) {
        if (board[row][i] == num || board[i][col] == num) {
            return false;
        }
    }

    
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[startRow + i][startCol + j] == num) {
                return false;
            }
        }
    }

    return true;
}


bool findEmpty(int board[N][N], int &row, int &col) {
    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            if (board[row][col] == 0) {
                return true;
            }
        }
    }
    return false;
}


bool solveSudoku(int board[N][N]) {
    int row, col;

    
    if (!findEmpty(board, row, col)) {
        return true; 
    }

    
    for (int num = 1; num <= 9; num++) {
        if (isSafe(board, row, col, num)) {
            
            board[row][col] = num;
            
            if (solveSudoku(board)) {
                return true;
            }

            board[row][col] = 0;
        }
    }

    return false; // No sol
}

int main() {
    int sudokuBoard[N][N] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    cout << "Unsolved Sudoku Puzzle:" << endl;
    printBoard(sudokuBoard);

    if (solveSudoku(sudokuBoard)) {
        cout << "\nSolved Sudoku Puzzle:" << endl;
        printBoard(sudokuBoard);
    } else {
        cout << "\nNo solution exists." << endl;
    }

    return 0;
}
