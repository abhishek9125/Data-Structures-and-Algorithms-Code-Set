#include <bits/stdc++.h> 

bool detectCycleByBfs(unordered_map<int, list<int>> adjList,unordered_map<int, bool>& visited, unordered_map<int, int>& parent, int node) {
    
    queue<int> q;
    q.push(node);
    visited[node] = true;
    parent[node] = -1;
    
    while(!q.empty()) {
        
        int frontNode = q.front();
        q.pop();
        
        for(auto i : adjList[frontNode]) {
            
            if(visited[i] && i != parent[frontNode]) {
                return true;
            }
            
            if(!visited[i]) {
                q.push(i);
                visited[i] = true;
                parent[i] = frontNode;
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
    unordered_map<int, int> parent;
    
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            bool isCyclicBfs = detectCycleByBfs(adjList, visited, parent, i); 
            if(isCyclicBfs) {
                return "Yes";
            }
        }
    }
    return "No";
}
