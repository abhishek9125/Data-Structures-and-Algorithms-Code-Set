#include <bits/stdc++.h> 
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    unordered_map<int, list<int>> adjList;

    for(auto i : edges) {
        adjList[i[0]].push_back(i[1]);
    }
    
    vector<int> indegree(v, 0);
    
    for(auto i : adjList) {
        for(auto j : i.second) {
            indegree[j]++;
        }
    }
    
    queue<int> q;
    
    for(int i = 0; i < v; i++) {
        if(indegree[i] == 0) {
            q.push(i);
        }
    }
   
    vector<int> result;
    
    while(!q.empty()) {
        
        int frontNode = q.front();
        q.pop();
        
        result.push_back(frontNode);
        
        for(auto i : adjList[frontNode]) {
            
            indegree[i]--;
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
        
    }
    return result;
}