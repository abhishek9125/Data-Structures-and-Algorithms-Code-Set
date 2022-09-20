class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int K)
    {
        sort(candies, candies + N);
        
        int mini = 0;
        int buy = 0;
        int save = N - 1;
        
        while(buy <= save) {
            mini += candies[buy++];
            save = save - K;
        }
        
        int maxi = 0;
        buy = N - 1;
        save = 0;
        
        while(save <= buy) {
            maxi += candies[buy--];
            save = save + K;
        }
        
        return {mini, maxi};
    }
};