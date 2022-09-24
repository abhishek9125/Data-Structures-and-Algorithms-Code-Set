#include<bits/stdc++.h>
vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
    
    unordered_map<int, list<int>> adjList;
    
    for(int i = 0; i < edges.size(); i++) {
        adjList[edges[i].first].push_back(edges[i].second);
        adjList[edges[i].second].push_back(edges[i].first);
    }
    
    unordered_map<int, bool> visited;
    unordered_map<int, int> parent(n);

    queue<int> q;
    
    q.push(s);
    parent[s] = -1;
    visited[s] = true;
    
    while(!q.empty()) {
        int frontNode = q.front();
        q.pop();
        
        for(auto i : adjList[frontNode]) {
            if(!visited[i]) {
                visited[i] = true;
                parent[i] = frontNode;
                q.push(i);
            }
        }
    }
    
    vector<int> result;
    int currentNode = t;
    while(currentNode != s) {
        result.push_back(currentNode);
        currentNode = parent[currentNode];
    }
    result.push_back(s);
    reverse(result.begin(), result.end());
    return result;
}
