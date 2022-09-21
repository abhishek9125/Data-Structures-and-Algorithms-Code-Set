class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int cs = nums[0];
        int ms = nums[0];
        
        for(int i = 1; i < nums.size(); i++) {
            cs = cs + nums[i];
            ms = max(ms, cs);
            if(cs < 0) {
                cs = 0;
            }    
        }
        
        return ms;
    }
};