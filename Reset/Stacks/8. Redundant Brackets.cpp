#include <bits/stdc++.h> 
bool findRedundantBrackets(string &s)
{
    // Write your code here.
    stack<char> st;
    
    for(auto i : s) {
        char ch = i;
        
        if(ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            st.push(ch);
        } else {
            if(ch == ')') {
                bool isRedundant = true;
                
                while(!st.empty() && st.top() != '(') {
                    char top = st.top();
                    if(top == '+' || top == '-' || top == '*' || top == '/') {
                        isRedundant = false;
                    }
                    st.pop();
                }
                
                if(isRedundant) {
                    return true;
                }
                st.pop();
            }
        }
    }
    return false;
}
