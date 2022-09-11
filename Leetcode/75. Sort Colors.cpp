class Solution {
public:
    void sortColors(vector<int>& nums) {
        int start = 0;
        int end = nums.size() - 1;
        
        int current = 0;
        
        while(current <= end) {
            if(nums[current] == 0) {
                swap(nums[start], nums[current]);
                start++;
                current++;
            } else if(nums[current] == 2) {
                swap(nums[current], nums[end]);
                end--;
            } else {
                current++;
            }
        }
        
        return;
        
    }
};