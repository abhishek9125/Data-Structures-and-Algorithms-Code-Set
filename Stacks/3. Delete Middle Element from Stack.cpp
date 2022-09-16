#include <bits/stdc++.h> 

void solve(stack<int>&inputStack, int count, int N) {
    
    if(count == N / 2) {
        inputStack.pop();
        return;
    }
    int element = inputStack.top();
    inputStack.pop();
    solve(inputStack, count + 1, N);
    inputStack.push(element);
    return;
}

void deleteMiddle(stack<int>&inputStack, int N){
	
   // Write your code here
   int count = 0;
   solve(inputStack, count, N);
}