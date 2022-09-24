#include<bits/stdc++.h>
bool detectCyclicDfs(int node, unordered_map<int, list<int>>& adjList, unordered_map<int, bool>& visited, unordered_map<int, bool>& dfsVisited) {
    
    visited[node] = true;
    dfsVisited[node] = true;
    for(auto i : adjList[node]) {
        
        if(visited[i] && dfsVisited[i]) {
            return true;
        }
        
        if(!visited[i]) {
            bool cycle = detectCyclicDfs(i, adjList, visited, dfsVisited);
            if(cycle) {
                return true;
            }
        }
    }

    dfsVisited[node] = false;
    return false;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
    
    unordered_map<int, list<int>> adjList;

    for(auto i : edges) {
        adjList[i.first].push_back(i.second);
    }
                
    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsVisited;
    
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            bool cycle = detectCyclicDfs(i, adjList, visited, dfsVisited);
            if(cycle) {
                return 1;
            }
        }
    }
                
    return 0; 
}