class Solution {
public:
    
    void solve(vector<vector<int>>& result, vector<int>& nums, int index) {
        if(index == nums.size()) {
            result.push_back(nums);
            return;
        }
        
        for(int j = index; j < nums.size(); j++) {
            swap(nums[index],nums[j]);    
            solve(result, nums, index + 1);
            swap(nums[index],nums[j]);    

        }
        
        return;
        
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        
        solve(result, nums, 0);
        
        return result;
    }
};