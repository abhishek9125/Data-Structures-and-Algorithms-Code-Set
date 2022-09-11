#include<bits/stdc++.h>

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    // Write your code here. 
    
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
    
    for(int i = 0; i < k; i++) {
        pq.push(make_pair(kArrays[i][0], make_pair(i,0)));
    }
    
    vector<int> result;
    
    while(!pq.empty()) {
        pair<int, pair<int, int>> p = pq.top();
        pq.pop();
        result.push_back(p.first);
        int row = p.second.first;
        int col = p.second.second;
        if(col + 1 < kArrays[row].size()) {
            pq.push(make_pair(kArrays[row][col + 1], make_pair(row, col + 1 )));
        }
    }
    
    return result;
    
}

