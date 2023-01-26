#include <bits/stdc++.h>
using namespace std;

int countSubsets(vector<int>& arr, int n, int i, int sum) {

    if(i == n) {
        if(sum == 0) {
            return 1;
        } else {
            return 0;
        }
    }

    int included = countSubsets(arr, n, i + 1, sum - arr[i]);
    int excluded = countSubsets(arr, n, i + 1, sum);

    return (included + excluded);
}

int main() {

    vector<int> arr = {1, 2, 3, 4, 5};
    int x = 6;

    cout << countSubsets(arr, arr.size(), 0, x) << endl;

    return 0;

}

