#include<bits/stdc++.h>

int signum(int a, int b) {
    if(a == b) {
        return 0;
    } else if(a > b) {
        return 1;
    } else {
        return -1;
    }    
}

void findMedian(int element, priority_queue<int>& maxQ, priority_queue<int, vector<int>, greater<int>>& minQ, int& median) {
    
    switch(signum(maxQ.size(), minQ.size())) {
        case 0: 
             if(element > median) {
                 minQ.push(element);
                 median = minQ.top();
             } else {
                 maxQ.push(element);
                 median = maxQ.top();
             }
            break;
        
        case 1:
            if(element > median) {
                minQ.push(element);
                median = (maxQ.top() + minQ.top()) / 2;
            } else {
                minQ.push(maxQ.top());
                maxQ.pop();
                maxQ.push(element);
                median = (maxQ.top() + minQ.top()) / 2;                                
            }
            break;
            
        case -1:
            if(element > median) {
                maxQ.push(minQ.top());
                minQ.pop();
                minQ.push(element);
                median = (maxQ.top() + minQ.top()) / 2;                
            } else {
                maxQ.push(element);
                median = (maxQ.top() + minQ.top()) / 2;
            }
            break;
    }
    
}

vector<int> findMedian(vector<int> &arr, int n){
    priority_queue<int> maxQ;
    priority_queue<int, vector<int>, greater<int>> minQ;
    
    vector<int> result;
    int median = -1;
    
    for(int i = 0; i < n; i++) {
        findMedian(arr[i], maxQ, minQ, median);
        result.push_back(median);
    }
    
    return result;
}
