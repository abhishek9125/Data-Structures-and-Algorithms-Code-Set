#include <iostream>
using namespace std;

int main() {

    int n;
    cin >> n;

    int a[n];

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int target = 16;

    int i = 0;
    int j = n - 1;

    while(i < j) {
        if(a[i] + a[j] < target) {
            i++;
        } else if (a[i] + a[j] > target) {
            j--;
        } else {
            cout << a[i] << " , " << a[j] << endl;
            i++;
            j--;
        }
    }
 

    return 0;
}
