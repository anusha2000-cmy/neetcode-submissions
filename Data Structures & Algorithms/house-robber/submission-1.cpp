class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1,-1);
        return dfs(n,nums,dp);
    }

    int dfs(int n,vector<int>& nums,vector<int>& dp){
        if(n==1){
            return nums[0];
        }
        if(n==2){
            return max(nums[0],nums[1]);
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        else{
            dp[n] = max(dfs(n-1,nums,dp),dfs(n-2,nums,dp)+nums[n-1]);
        }
        return dp[n];
    }


};
