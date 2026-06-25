class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res=0;
        int mini=prices[0];
        for(int i=0;i<prices.size();i++){
            res=max(res,prices[i]-mini);
            mini=min(prices[i],mini);
        }
        return res;
    }
};
