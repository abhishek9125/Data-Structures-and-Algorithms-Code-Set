queue<int> rev(queue<int> q)
{
    stack<int> s;
    
    while(!q.empty()) {
        int element = q.front();
        q.pop();
        s.push(element);
    }
    
    while(!s.empty()) {
        q.push(s.top());
        s.pop();
    }
 
    return q;
    
}