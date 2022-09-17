#include <bits/stdc++.h> 

void pushBoard(vector<vector<int>>& board, vector<vector<int>>& result, int n) {
    
    vector<int> temp;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            temp.push_back(board[i][j]);
        }
    }
    
    result.push_back(temp);
}

bool isSafe(int row, int col, vector<vector<int>>& board, int n) {
    
    int x = row;
    int y = col;
    
    while(y >= 0) {
        if(board[x][y] == 1) {
            return false;
        }
        y--;
    }
    
    x = row;
    y = col;
    
    while(x >= 0 && y >= 0) {
        if(board[x][y] == 1) {
            return false;
        }
        x--;
        y--;
    }
    
    x = row;
    y = col;
    
    while(x < n && y >= 0) {
        if(board[x][y] == 1) {
            return false;
        }
        x++;
        y--;
    }
    
    return true;
}

void solve(int col, vector<vector<int>>& board, vector<vector<int>>& result, int n) {
    
    if(col == n) {
        pushBoard(board, result, n);
        return;
    }
    
    for(int row = 0; row < n; row++) {
        if(isSafe(row, col, board, n)) {
            board[row][col] = 1;
            solve(col + 1, board, result, n);
            board[row][col] = 0;
        }
    }
    
    return;
}

vector<vector<int>> nQueens(int n) {
    vector<vector<int>> result;
    vector<vector<int>> board(n, vector<int>(n, 0));
    
    solve(0, board, result, n);
    
    return result;
}