// https://www.codingninjas.com/codestudio/problems/delete-middle-element-from-stack_985246?leftPanelTab=0

#include <bits/stdc++.h> 

void solve(stack<int>&inputStack, int size, int count) {

   if(count == size/2) {
      inputStack.pop();
      return;
   }

   int num = inputStack.top();
   inputStack.pop();
   solve(inputStack, size, count + 1);
   inputStack.push(num);
}

void deleteMiddle(stack<int>&inputStack, int N){
   // Write your code here
   int count = 0;
   solve(inputStack, N, count);
}