class Solution {
public:
    int mySqrt(int x) {
        int start = 0;
        int end = x;
        int ans = -1;
        
        while(start <= end) {
            long long int mid = start + (end - start) / 2;
            long long int square = mid*mid;
            if(square == x) {
                return mid;
            } else if(square < x) {
                ans = mid;
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        
        return ans;
    }

    double morePrecision(int n, int precision, int tempSol) {
        double factor = 1;
        double ans = tempSol;
        
        for(int i = 0; i < precision; i++) {
            factor = factor / 10;

            for(double j = 0; j*j < n; j = j + factor) {
                ans = j;
            }
        }
        return ans;
    }

};