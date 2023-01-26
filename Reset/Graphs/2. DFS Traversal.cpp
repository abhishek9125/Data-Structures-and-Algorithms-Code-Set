#include <bits/stdc++.h> 

void createAdjacencyList(vector<vector<int>> &edges, unordered_map<int, list<int>>& adjList) {
    for(auto i : edges) {
        adjList[i[0]].push_back(i[1]);
        adjList[i[1]].push_back(i[0]);
    }   
    return;
}

void dfs(unordered_map<int, list<int>>& adjList, unordered_map<int, bool>& visited, vector<int>& temp, int node) {
    temp.push_back(node);
    visited[node] = true;
    for(auto i : adjList[node]) {
        if(!visited[i]) {
            dfs(adjList, visited, temp, i);
        }
    }   
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    unordered_map<int, list<int>> adjList;
    unordered_map<int, bool> visited;
    
    createAdjacencyList(edges, adjList);
    
    vector<vector<int>> result;
    
    for(int i = 0; i < V; i++) {
        if(!visited[i]) {
            vector<int> temp;
            dfs(adjList, visited, temp, i);
            result.push_back(temp);
        }   
    }
    return result;
}