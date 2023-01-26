#include <bits/stdc++.h> 
int findMinimumCost(string str) {
  // Write your code here
    
    if(str.length() % 2 == 1) {
        return -1;
    }
    
    stack<int> s;
    
    for(auto i : str) {
        char ch = i;
        if(ch == '{') {
            s.push(ch);
        } else {
            if(!s.empty() && s.top() == '{') {
                s.pop();
            } else {
                s.push(ch);
            }
        } 
    }
    
    int a = 0;
    int b = 0;
    
    while(!s.empty()) {
        if(s.top() == '{') {
            a++;
        } else {
            b++;
        }
        s.pop();
    }
    
    int ans = (a + 1) / 2 + (b + 1) / 2;
    return ans;
}