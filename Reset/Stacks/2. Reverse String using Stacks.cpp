#include <iostream>
#include <stack>
using namespace std;

int main() {

    string str = "Abhishek";

    stack<char> s;

    for(auto i : str) {
        s.push(i);
    }

    while(!s.empty()) {
        cout << s.top();
        s.pop();
    }

    return 0;

}
