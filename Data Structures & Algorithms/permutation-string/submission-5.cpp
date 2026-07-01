class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length()>s2.length()){
            return false;
        }
        int ss1[26]={0};
        int ss2[26]={0};
        
        for(int i=0;i<s1.length();i++){
            ss1[s1[i]-'a']++;
            ss2[s2[i]-'a']++;
        }

        int l=0,r=s1.length();
        while(r<=s2.length()){
            int matches=0;
            for(int i=0;i<26;i++){
                if(ss1[i]==ss2[i])
                    matches++;
            }
            if(matches==26)
                return true;

            if(r<s2.length()){
                ss2[s2[l]-'a']--;
                l++;
                ss2[s2[r]-'a']++;
                r++;
            }
            else{
                break;
            }
        }
        return false;
    }
};
