class Solution {
public:
    
    bool isPossible(vector<int>& weights, int n, int m, int mid) {
        int daysCount = 1;
        int weightSum = 0;

        for(int i = 0; i < n; i++) {
            if(weightSum + weights[i] <= mid) {
                weightSum += weights[i];
            } else {
                daysCount++;
                weightSum = weights[i];

                if(daysCount > m || weights[i] > mid) {
                    return false;
                }
            }
        }
        return true;
    }

    
    int shipWithinDays(vector<int>& weights, int days) {
        int start = 0;
        int end = 0;
        
        for(auto i : weights) {
            end += i;
        }
        
        int ans = -1;
    
        while(start <= end) {
            int mid = start + (end - start) / 2;

            if(isPossible(weights, weights.size(), days, mid)) {
                ans = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return ans;

    }
};