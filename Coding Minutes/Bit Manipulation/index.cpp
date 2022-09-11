#include<iostream>
using namespace std;

void checkOddorEven(int n) {
    if(n & 1) {
        cout << "Odd Number" << endl;
    } else {
        cout << "Even Number" << endl;
    }
}

int getIthBit(int n, int i) {
    int mask = 1 << i;
    return n & mask > 0 ? 1 : 0;
}

void setIthBit(int &n, int i) {
    int mask = 1 << i;
    n = n | mask;
} 

void clearIthBit(int &n, int i) {
    int mask = ~(1 << i);
    n = n & mask;
}

void updateIthBit(int &n, int i, int v) {
    clearIthBit(n, i);
    int mask = v << i;
    n = n | mask;
}

void clearLastIBits(int &n, int i) {
    int mask = -1 << i;
    n = n & mask;
}

void clearBitsInRange(int &n, int i, int j) {
    int a = (~0) << (j + 1);
    int b = (1 << i) - 1;
    int mask = a | b;
    n = n & mask;
}

bool checkPowerOfTwo(int n) {
    return (n&(n-1)) == 0 ? true : false
}

int countSetBits(int n) {
    int count = 0;
    while(n!=0) {
        int lastBit = n & 1;
        if(lastBit) count++;
        n = n >> 1;
    }
    return count;
}

int countBitsOptimised(int n) {
    int ans = 0;
    while(n > 0) {
        n = n & (n-1);
        ans++;
    }
    return ans;
}

int main() {
    int n;
    cin >> n;

    checkOddorEven(n);

    cout << "Ith Bit" << getIthBit(n, 1) << endl;

}