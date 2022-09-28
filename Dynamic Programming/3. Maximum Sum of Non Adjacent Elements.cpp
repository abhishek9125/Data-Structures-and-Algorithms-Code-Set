#include <bits/stdc++.h> 

int solveRec(vector<int>& nums, int n) {
    if(n < 0) return 0;
    if(n == 0)  return nums[0];
    int incl = solveRec(nums, n - 2) + nums[n];
    int excl = solveRec(nums, n - 1);
    return max(incl, excl);
}

int solveMemo(vector<int>& nums, int n, vector<int>& dp) {
    if(n < 0) return 0;
    if(n == 0)  return nums[0];
    if(dp[n] != -1) return dp[n];
    int incl = solveRec(nums, n - 2) + nums[n];
    int excl = solveRec(nums, n - 1);
    return dp[n] = max(incl, excl);
}

int solveTabular(vector<int>& nums) {
    int n = nums.size();
    if(n==1) {
        return nums[0];
    }
    vector<int> dp(n, 0);
    dp[0] = nums[0];
    dp[1] = nums[1];
    for(int i = 1; i < n; i++) {
        int incl = dp[i-2] + nums[i];
        int excl = dp[i-1] + 0;
        dp[i] = max(incl, excl);
    }
    return dp[n-1];
}

int solveTabularOptimised(vector<int>& nums) {
    int n = nums.size();
    int prev2 = 0;
    int prev1 = nums[0];
    for(int i = 1; i < n; i++) {
        int incl = prev2 + nums[i];
        int excl = prev1 + 0;
        prev2 = prev1;
        prev1 = max(incl, excl);
    }
    return prev1;
}

int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n = nums.size();
//     int ans = solveRec(nums, n-1);
//     vector<int> dp(n, -1);
//     int ans = solveRec(nums, n-1);
    int ans = solveTabularOptimised(nums);
    return ans;
}