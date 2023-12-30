#include <iostream>
using namespace std;

int main() {

    int n;
    cin >> n;

    int a[n];

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int currentSum = 0;
    int maximumSum = 0;
    int left = -1;
    int right = -1;

    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            currentSum = 0;
            for(int k = i; k <= j; k++) {
                currentSum += a[k];
            }
            if(currentSum > maximumSum) {
                maximumSum = currentSum;
                left = i;
                right = j;
            }
        }
    }

    cout << "Maximum Sum : " << maximumSum << endl;
    cout << "Array Index are from " << left << " to " << right;

    return 0;
}
