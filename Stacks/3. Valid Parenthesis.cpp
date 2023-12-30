// https://www.codingninjas.com/codestudio/problems/valid-parenthesis_795104?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0

bool isValidParenthesis(string expression) {
    // Write your code here.

    stack<char> s;

    for(auto e : expression) {

        if(!s.empty() && ((e == '}' && s.top() == '{') || (e == ')' && s.top() == '(') || (e == ']' && s.top() == '['))) {
            s.pop();
        } else {
            s.push(e);
        }
    }
    return s.empty();
}