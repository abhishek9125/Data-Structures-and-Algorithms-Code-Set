queue<int> modifyQueue(queue<int> q, int k) {
    // add code here.
    
    stack<int> s;
    
    for(int i = 0; i < k; i++) {
        s.push(q.front());
        q.pop();
    }
    
    while(!s.empty()) {
        q.push(s.top());
        s.pop();
    }
    
    for(int i = 0; i < (q.size() - k); i++) {
        int element = q.front();
        q.pop();
        q.push(element);
    }
    
    return q;
}