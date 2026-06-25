class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.length();
        int res=0;
        int maxf=0;
        unordered_map<char,int> m;
        int l=0,r=0;
        while(r<n){
            m[s[r]]++;
            maxf=max(maxf,m[s[r]]);
            while((r-l+1)-maxf>k){
                m[s[l]]--;
                l++;
            }
            res = max(res,r-l+1);
            r++;
        }
        return res;
    }
};
