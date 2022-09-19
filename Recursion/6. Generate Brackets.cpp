#include <bits/stdc++.h>
using namespace std;

void countSubsets(string output, int n, int open, int close, int index) {

    if(index == 2*n) {
        cout << output << endl;
        return;
    }

    if(open < n) {
        countSubsets(output + '(', n, open + 1, close, index + 1);
    }

    if(close < open) {
        countSubsets(output + ')', n, open, close + 1, index + 1);
    }
}

int main() {

    string output = "";
    int n;
    cin >> n;
    countSubsets(output, n, 0, 0, 0);

    return 0;

}

