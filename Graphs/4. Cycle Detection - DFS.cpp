#include <bits/stdc++.h> 

bool detectCycleByDfs(unordered_map<int, list<int>> adjList,unordered_map<int, bool>& visited, int parent, int node) {
    
    visited[node] = true;
    
    for(auto i : adjList[node]) {
        if(visited[i] && i != parent) {
            return true;
        }
        
        if(!visited[i]) {
            visited[i] = true;
            bool isCyclic = detectCycleByDfs(adjList, visited, node, i);
            if(isCyclic) {
                return true;
            }
        }
        
    }
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.
    unordered_map<int, list<int>> adjList;

    for(auto i : edges) {
        adjList[i[0]].push_back(i[1]);
        adjList[i[1]].push_back(i[0]);
    }
    
    unordered_map<int, bool> visited;
    
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            bool isCyclicBfs = detectCycleByDfs(adjList, visited, -1, i); 
            if(isCyclicBfs) {
                return "Yes";
            }
        }
    }
    return "No";
}
