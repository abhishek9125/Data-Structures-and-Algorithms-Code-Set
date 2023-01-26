class Solution {
public:
    
    void solve(vector<int>& nums, vector<int>& output, int index, vector<vector<int>>& result) {
        
        if(index == nums.size()) {
            result.push_back(output);
            return;
        }
        
        output.push_back(nums[index]);
        solve(nums, output, index + 1, result);
        output.pop_back();
        solve(nums, output, index + 1, result);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> result;
        vector<int> output;
        
        solve(nums, output, 0, result);
        
        return result;
    }
};