class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int x = 0;
        int y = 0;
        for(int i=0;i<=nums.size();i++){
            y = y^i;
        }
        for(auto i : nums){
            x = x^i;
        }
        return x^y;
    }
};