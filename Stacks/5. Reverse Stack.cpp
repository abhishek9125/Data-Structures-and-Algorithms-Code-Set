
void insertAtBottom(stack<int> &s, int num) {
    if(s.empty()) {
        s.push(num);
        return;
    }

    int element = s.top();
    s.pop();
    insertAtBottom(s, num);
    s.push(element);
}

void solve(stack<int> &s) {

    if(s.size() == 1) {
        return;
    }

    int num = s.top();
    s.pop();
    solve(s);
    insertAtBottom(s, num);
}

void reverseStack(stack<int> &s) {
    // Write your code here
    if(s.empty()) {
        return;
    }
    solve(s);
}