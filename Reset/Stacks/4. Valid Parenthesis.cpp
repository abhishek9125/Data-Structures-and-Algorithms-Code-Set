bool isValidParenthesis(string expression)
{
    // Write your code here.
    
    stack<char> s;
    
    for(auto i: expression) {
        char ch = i;
        
        if(!s.empty()) {
            if((ch == ')' && s.top() == '(') || 
               (ch == '}' && s.top() == '{') || 
               (ch == ']' && s.top() == '[')) {
                    s.pop();
            } else {
                s.push(i);
            }
        } else {
            s.push(i);
        }
    }
    
    return s.empty();
}