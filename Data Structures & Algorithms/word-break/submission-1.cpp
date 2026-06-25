class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.length()+1,false);
        dp[s.length()]=true;
        for(int i=s.length()-1;i>=0;i--){
            for(string w:wordDict){
                if(i+w.length()<=s.length() && s.substr(i,w.length())==w){
                    if(dp[i+w.length()]){
                        dp[i] = true;
                    }
                }
            }
        }
        return dp[0];
    }
};
