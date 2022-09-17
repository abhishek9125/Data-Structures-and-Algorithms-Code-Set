#include <bits/stdc++.h> 

bool isSafe(int row, int col, vector<vector<int>>& board, int val, int n) {
    
    for(int i = 0; i < n; i++) {
        if(board[row][i] == val) {
            return false;
        }
        
        if(board[i][col] == val) {
            return false;
        }
    }
    
    int x = (row / 3) * 3;
    int y = (col / 3) * 3;
    
    for(int i = x; i < x + 3; i++) {
        for(int j = y; j < y + 3; j++) {
            if(board[i][j] == val){
                return false;
            }
        }
    }
    
    return true;
}

bool solve(vector<vector<int>>& board) {
    
    int n = board[0].size();
    
    for(int row = 0; row < n; row++) {
        for(int col = 0; col < n; col++) {
            if(board[row][col] == 0) {
                for(int val = 1; val < 10; val++) {
                    if(isSafe(row, col, board, val, n)) {
                        board[row][col] = val;
                        bool isPossible = solve(board);
                        if(isPossible) {
                            return true;
                        }
                        board[row][col] = 0;
                    }    
                } 
                return false;
            }
        }
    }
    
    return true;
}

void solveSudoku(vector<vector<int>>& sudoku)
{
    // Write your code here
    // No need to print the final sudoku
    // Just fill the values in the given matrix
    solve(sudoku);
}