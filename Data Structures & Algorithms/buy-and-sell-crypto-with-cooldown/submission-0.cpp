class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        return dfs(prices,0,true,dp);
    }

    int dfs(vector<int>& prices,int i,bool buy,vector<vector<int>>& dp){
        if(i>=prices.size())
            return 0;
        if(dp[i][buy]!=-1){
            return dp[i][buy];
        }
        int temp = dfs(prices,i+1,buy,dp);
        if(buy){
            int t1=dfs(prices,i+1,false,dp)-prices[i];
            return dp[i][buy]=max(temp,t1);
        }else{
            int t2=dfs(prices,i+2,true,dp)+prices[i];
            return dp[i][buy]=max(temp,t2);
        }
    }
};
