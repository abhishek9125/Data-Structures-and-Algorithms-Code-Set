class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        
        for(int i = 0; i < 32; i++) {
            
            int count = 0;
            int mask = 1 << i;

            for(auto num : nums) {
                if(mask & num) {
                    count ++;
                }
            }
            if(count % 3 != 0) {
                ans = ans | mask;
            }
        }
        
        return ans;
        
    }
};