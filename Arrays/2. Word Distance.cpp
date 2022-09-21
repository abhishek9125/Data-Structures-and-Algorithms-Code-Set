#include <bits/stdc++.h> 

int getDistance(vector<string>& arr, string word1, string word2) {
    
    int w1 = -1;
    int w2 = -1;
    
    int mini = arr.size();
    
    for(int i = 0; i < arr.size(); i++) {
        
        if(arr[i] == word1) {
            w1 = i;
        }
        
        if(arr[i] == word2) {
            w2 = i;
        }
        
        if(w1 != -1 && w2 != -1) {
            mini = min(mini, abs(w1 - w2));        
        }
    }
    return mini;
}

vector<int> wordDistance(int n, int q, vector<string>& arr, vector<vector<string>>& queries){
    // Write your code here.
    
    vector<int> result;
    while(q--) {
        
        string word1 = queries[queries.size() - q - 1][0];
        string word2 = queries[queries.size() - q - 1][1]; 
        
        int distance = getDistance(arr, word1, word2);
        result.push_back(distance);
    }
    return result;
}