class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return dfs(n,dp);
    }

    int dfs(int n,vector<int>& dp){
        if(n<=2)
            return n;
        if(dp[n]!=-1)
            return dp[n];
        else
            dp[n] = dfs(n-1,dp) + dfs(n-2,dp);
        return dp[n];
    }
};
