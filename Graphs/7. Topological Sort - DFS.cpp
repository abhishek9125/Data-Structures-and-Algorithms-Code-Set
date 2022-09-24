#include <bits/stdc++.h> 

void dfs(unordered_map<int, list<int>>& adjList, vector<bool>& visited, vector<int>& result, int node) {
    
    visited[node] = true;
    
    for(auto i : adjList[node]) {
        if(!visited[i]) {
            dfs(adjList, visited, result, i);
        }
    }
    
    result.push_back(node);
    return;
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    unordered_map<int, list<int>> adjList;

    for(auto i : edges) {
        adjList[i[0]].push_back(i[1]);
    }
    
    vector<bool> visited(v);
    vector<int> result;
    
    for(int i = 0; i < v; i++) {
        if(!visited[i]) {
            dfs(adjList, visited, result, i);
        }
    }
    
    reverse(result.begin(), result.end());
    return result;
}