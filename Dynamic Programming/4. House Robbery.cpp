#include <bits/stdc++.h> 

long long int solve(vector<int>& nums) {
    int n = nums.size();
    long long int prev2 = 0;
    long long int prev1 = nums[0];
    
    for(int i = 1; i < n; i++) {
        long long int incl = prev2 + nums[i];
        long long int excl = prev1 + 0;
        prev2 = prev1;
        prev1 = max(incl, excl);
    }
    return prev1;
}

long long int houseRobber(vector<int>& nums)
{
    // Write your code here.
    int n = nums.size();
    if(n == 1) return nums[0];
    
    vector<int> first, second;
    
    for(int i = 0; i < n; i++) {
        if(i != n - 1) {
            first.push_back(nums[i]);
        }
        if(i != 0) {
            second.push_back(nums[i]);
        }
    }
    
    return max(solve(first), solve(second));
}