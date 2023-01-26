#include <bits/stdc++.h> 

bool isSafe(int x, int y, vector<vector<int>>& arr, int n, vector<vector<int>>& visited) {
    if((x >= 0 && x < n ) && (y >=0 && y < n) && visited[x][y] != 1 && arr[x][y] == 1) {
        return true;
    }
    return false;
}

void solve(int x, int y, vector<vector<int>>& arr, int n, vector<string>& result, vector<vector<int>>& visited, string path) {
    
    if((x == n - 1) && (y == n - 1)) {
        result.push_back(path);
        return;
    }
    
    visited[x][y] = 1;
    
    
    if(isSafe(x + 1, y, arr, n, visited)) {
        solve(x + 1, y, arr, n, result, visited, path + 'D');
    }
    
    if(isSafe(x, y - 1, arr, n, visited)) {
        solve(x, y - 1, arr, n, result, visited, path + 'L');
    }
    
    if(isSafe(x, y + 1, arr, n, visited)) {
        solve(x, y + 1, arr, n, result, visited, path + 'R');
    }
    
    if(isSafe(x - 1, y, arr, n, visited)) {
        solve(x - 1, y, arr, n, result, visited, path + 'U');
    }
    
    visited[x][y] = 0;
    
    return;
}

vector<string> searchMaze(vector<vector<int>>& arr, int n) {
    
    vector<string> result;
    string path = "";
    vector<vector<int>> visited(n, vector<int>(n, 0));
    
    if(arr[0][0] == 0) {
        return result;
    }
    
    solve(0, 0, arr, n, result, visited, path);
    return result;
}