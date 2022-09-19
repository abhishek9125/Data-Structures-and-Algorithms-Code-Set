#include <bits/stdc++.h>
using namespace std;

string keypad[] = { "", "", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRD", "TUV", "WXYZ" };

void printKeypad(string input, string output, int i) {

    if(input[i] == '\0') {
        cout << output << endl;
        return;
    }

    int digit = input[i] - '0';

    if((digit == 0) || (digit == 1)) {
        printKeypad(input, output, i + 1);
    }

    for(int j = 0; j < keypad[digit].length(); j++) {
        printKeypad(input, output + keypad[digit][j], i + 1);
    }

    return;
}

int main() {

    string input;
    cin >> input;

    string output;

    printKeypad(input, output, 0);

    return 0;

}

