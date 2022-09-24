#include<bits/stdc++.h>

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
    
    unordered_map<int, list<int>> adjList;

    for(auto i : edges) {
        adjList[i.first].push_back(i.second);
    }
    
    vector<int> indegree(n + 1, 0);
    
    for(auto i : adjList) {
        for(auto j : i.second) {
            indegree[j]++;
        }
    }
    
    queue<int> q;
    
    for(int i = 1; i <= n; i++) {
        if(indegree[i] == 0) {
            q.push(i);
        }
    }
   
    int count = 0;
    
    while(!q.empty()) {
        
        int frontNode = q.front();
        q.pop();
        
        count++;
        
        for(auto i : adjList[frontNode]) {
            
            indegree[i]--;
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
        
    }
    return !(count == n);
}