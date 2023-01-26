class Solution{
public:
    int minimumDays(int S, int N, int M){
        int totalSundays = S / 7;
        int totalFoodRequired = S * M;
        int totalBuyingDays = S - totalSundays;
        int ans = 0;
        
        if(totalFoodRequired % N == 0) {
            ans = totalFoodRequired / N;
        } else {
           ans = (totalFoodRequired / N) + 1;
        }
        
        if(ans <= totalBuyingDays) {
            return ans;
        } else {
            return -1;
        }
    }
};