// https://www.codingninjas.com/codestudio/problems/insert-an-element-at-its-bottom-in-a-given-stack_1171166?topList=love-babbar-dsa-sheet-problems&leftPanelTab=1

#include <bits/stdc++.h> 

void solve(stack<int>& myStack, int x) {
    if(myStack.empty()) {
        myStack.push(x);
        return;
    }

    int num = myStack.top();
    myStack.pop();
    solve(myStack, x);
    myStack.push(num);
}

stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    // Write your code here.
    solve(myStack, x);
    return myStack;
}
