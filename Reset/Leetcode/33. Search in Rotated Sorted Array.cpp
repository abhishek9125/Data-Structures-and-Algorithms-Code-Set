class Solution {
public:
    
    int getPivot(vector<int>& nums) {
        
        if(nums[0] < nums[nums.size() - 1]) {
            return 0;
        }
        
        int start = 0;
        int end = nums.size() - 1;
        
        while(start < end) {
            int mid = start + (end - start) / 2;
            
            if(nums[mid] >= nums[0]) {
                start = mid + 1;
            } else {
                end = mid;
            }
        }
        
        return start;
        
    }
    
    int binarySearch(vector<int>& nums, int target, int start, int end) {
        
        while(start <= end) {
            int mid = start + (end - start) / 2;

            if(nums[mid] == target) {
                return mid;
            } else if(nums[mid] < target) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        
        return -1;
        
    }
    
    int search(vector<int>& nums, int target) {
        
        int pivotElement = getPivot(nums);
        
        if(target >= nums[pivotElement] && target <= nums[nums.size() - 1]) {
            return binarySearch(nums, target, pivotElement, nums.size() - 1);
        } else {
            return binarySearch(nums, target, 0, pivotElement - 1);
        }        
    }
};