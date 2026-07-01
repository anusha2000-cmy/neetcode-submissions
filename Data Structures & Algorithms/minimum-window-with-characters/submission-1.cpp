class Solution {
public:
    string minWindow(string s, string t) {
        if(t.length()>s.length()){
            return "";
        }
        unordered_map<char,int> ms;
        unordered_map<char,int> mt;
        int resLen = INT_MAX;
        for(char c:t){
            mt[c]++;
        }
        int mtSize=mt.size();
        int have=0;
        int first=-1;
        int l=0,r=0;
        while(r<s.length()){
            ms[s[r]]++;
            if(mt.count(s[r]) && mt[s[r]]==ms[s[r]]){
                have++;
            }

            while(have==mtSize){
                if(r-l+1<resLen){
                    resLen=r-l+1;
                    first=l;
                }
                ms[s[l]]--;
                if(mt.count(s[l]) && mt[s[l]]>ms[s[l]]){
                    have--;
                }
                l++;
            }
            r++;
        }
        return resLen==INT_MAX? "" : s.substr(first,resLen);
    }
};
