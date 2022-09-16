#include<bits/stdc++.h>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // Write your code here.
    stack<int> s;
    s.push(-1);
    
    vector<int> result(n);
    
    for(int i = n - 1; i>=0 ; i--) {
        
        int element = arr[i];
        
        while(s.top() >= element) {
            s.pop();
        }
        
        result[i] = s.top();
        s.push(element);
    }
    
    return result;
}