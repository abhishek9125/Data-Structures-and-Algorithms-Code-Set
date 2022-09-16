#include <bits/stdc++.h> 

void sortRec(stack<int>& s, int element) {
    if((s.empty()) || (element >= s.top())) {
        s.push(element);
        return;
    }
    
    int ele = s.top();
    s.pop();
    sortRec(s, element);
    s.push(ele);
    return;
}

void solve(stack<int>& s) {
    
    if(s.empty()) {
        return;
    }
    
    int element = s.top();
    s.pop();
    solve(s);
    sortRec(s, element);
}

void sortStack(stack<int> &s)
{
    solve(s);
    return;
}