class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        unordered_map<char,int> m;
        int start=0;
        int end=0;
        int res=0;
        while(end<n){
            if(m.contains(s[end])){
                start=max(m[s[end]]+1,start);
            }
            m[s[end]]=end;
            res=max(res,end-start+1);
            end++;
        }
        return res;
    }
};
