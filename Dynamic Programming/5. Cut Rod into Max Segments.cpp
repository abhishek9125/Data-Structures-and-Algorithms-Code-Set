#include<bits/stdc++.h>

int solveRec(int n, int x, int y, int z){
    if(n == 0) return 0;
    if(n < 0) return INT_MIN;
    int ans1 = 1 + solveRec(n - x, x, y, z);
    int ans2 = 1 + solveRec(n - y, x, y, z);
    int ans3 = 1 + solveRec(n - z, x, y, z);  
    return max(ans1, max(ans2, ans3));
}

int solveMemo(int n, int x, int y, int z, vector<int>& dp){
    if(n == 0) return 0;
    if(n < 0) return INT_MIN;
    if(dp[n] != -1) return dp[n];
    int ans1 = 1 + solveMemo(n - x, x, y, z, dp);
    int ans2 = 1 + solveMemo(n - y, x, y, z, dp);
    int ans3 = 1 + solveMemo(n - z, x, y, z, dp);  
    return dp[n] = max(ans1, max(ans2, ans3));
}

int solveTabular(int n, int x, int y, int z) {
    vector<int> dp(n+1, INT_MIN);
    dp[0] = 0;
    for(int i = 1; i <= n; i++) {
        if(i>=x) {
            dp[i] = max(dp[i], 1 + dp[i-x]);
        }
        if(i>=y) {
            dp[i] = max(dp[i], 1 + dp[i-y]);
        }
        if(i>=z) {
            dp[i] = max(dp[i], 1 + dp[i-z]);
        }
    }
    return dp[n];
}

int cutSegments(int n, int x, int y, int z) {
//     int ans = solveRec(n, x, y, z);
//     vector<int> dp(n+1, -1);
//     int ans = solveMemo(n, x, y, z, dp);
	int ans = solveTabular(n, x, y, z);
    return ans < 0 ? 0 : ans;
}