class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size()+1,vector<int>(amount+1,-1));
        sort(coins.begin(),coins.end());
        return dfs(0,coins,amount,dp);
    }

    int dfs(int i,vector<int>& coins,int amount,vector<vector<int>>& dp){
        if(amount==0){
            return 1;
        }
        if(i>=coins.size()){
            return 0;
        }
        if(dp[i][amount]!=-1){
            return dp[i][amount];
        }
        if(coins[i]<=amount){
            int t1=dfs(i,coins,amount-coins[i],dp);
            int t3=dfs(i+1,coins,amount,dp);
            return dp[i][amount]=t1+t3;
        }
        else{
            return dp[i][amount]=0;
        }
    }
};
