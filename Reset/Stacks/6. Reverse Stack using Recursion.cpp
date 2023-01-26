
void insertAtBottom(stack<int>& myStack, int x) {
    
    if(myStack.empty()) {
        myStack.push(x);
        return;
    }
    
    int element = myStack.top(); 
    myStack.pop();
    insertAtBottom(myStack, x);
    myStack.push(element);
    return;
}


void solve(stack<int>& s) {
    
    if(s.size() == 1) {
        return;
    }
    
    int element = s.top();
    s.pop();
    solve(s);
    insertAtBottom(s, element);
}

void reverseStack(stack<int> &s) {
    // Write your code here
    if(s.empty()) {
        return;
    }
    solve(s);
    return;
}