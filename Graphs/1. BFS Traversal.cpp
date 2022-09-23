#include <bits/stdc++.h> 

void createAdjacencyList(vector<pair<int, int>> edges, unordered_map<int, set<int>>& adjList) {
    
    for(auto i : edges) {
        adjList[i.first].insert(i.second);
        adjList[i.second].insert(i.first);
    }
    
}

void bfs(unordered_map<int, set<int>>& adjList, unordered_map<int, bool>& visited, vector<int>& result, int node) {
    queue<int> q;
    q.push(node);
    visited[node] = true;
    while(!q.empty()) {
        
        int frontNode = q.front();
        q.pop();
        
        result.push_back(frontNode);
        
        for(auto i : adjList[frontNode]) {
            if(!visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    unordered_map<int, set<int>> adjList;
    vector<int> result;
    unordered_map<int, bool> visited;
    
    createAdjacencyList(edges, adjList);
    
    for(int i = 0; i < vertex; i++) {
        if(!visited[i]) {
            bfs(adjList, visited, result, i);
        }
    }
    
    return result;
    
}