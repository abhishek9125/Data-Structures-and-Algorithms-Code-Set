#include <iostream>
using namespace std;

int main() {

    int n;
    cin >> n;

    int a[n];
    int cumSum[n] = {0};
    int currentSum = 0;
    int maximumSum = 0;
    int left = 0;
    int right = 0;

    cin >> a[0];
    cumSum[0] = a[0];
    maximumSum = a[0];
    for(int i = 1; i < n; i++) {
        cin >> a[i];
        cumSum[i] = cumSum[i-1] + a[i];
        maximumSum = max(maximumSum, a[i]);
        left = i;
        right = i;
    }


 
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            currentSum = cumSum[j] - cumSum[i-1];
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
