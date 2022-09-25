#include <bits/stdc++.h> 
#define MOD 1000000007
// Recursive
int solve(int nStairs, int i) {
    if(i == 0) {
        return 1;
    }
    if(i < 0) {
        return 0;
    }
    return solve(nStairs, i - 1) + solve(nStairs, i - 2);
}

// Top Down Approach
int solveTD(int nStairs, int i, vector<int>& dp) {
    
    if(dp[i] != -1) {
      return dp[i];  
    }
    
    if(i == 0) {
        return 1;
    }
    if(i < 0) {
        return 0;
    }
    return dp[i] = ((solveTD(nStairs, i - 1, dp)  + solveTD(nStairs, i - 2, dp)) % MOD);
}

// Bottom Up Approach
int solveBU(int nStairs) {
    
    vector<int> dp(nStairs + 1);
    
    dp[0] = 1;
    dp[1] = 1;
    
    for(int i = 2; i <= nStairs; i++) {
        dp[i] = (dp[i-1] + dp[i-2]) % MOD;
    }
    
    return dp[nStairs];
}


int countDistinctWays(int nStairs) {
    //  Write your code here.
    // vector<int> dp(nStairs +1, -1);
    return solveBU(nStairs);
}