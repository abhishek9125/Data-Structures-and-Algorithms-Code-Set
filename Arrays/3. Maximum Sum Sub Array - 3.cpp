#include <iostream>
using namespace std;

int main() {

    int n;
    cin >> n;

    int a[n];
    int currentSum = 0;
    int maximumSum = 0;
    int left = 0;
    int right = 0;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
 
    for(int i = 0; i < n; i++) {
        currentSum = currentSum + a[i];
        if(currentSum < 0) {
            currentSum = 0;
            left = i + 1;
        }
        if(currentSum > maximumSum) {
            maximumSum = currentSum;
            right = i;
        }
    }

    cout << "Maximum Sum : " << maximumSum << endl;
    cout << "Array Index are from " << left << " to " << right;

    return 0;
}
