class Solution {
public:
    string longestPalindrome(string s) {
        int i=0;
        string res = "";
        while(i<s.length()){
            string str=checkPalindrome(s,i);
            if(str.length()>res.length()){
                res = str;
            }
            i++;
        }
        return res;
    }

    string checkPalindrome(string s,int i){
        int left=i-1;
        int right=i+1;
        //check odd

        while(left>=0 && right<s.length()){
            if(s[left]==s[right]){
                left--;
                right++;
            }
            else{
                break;
            }
        }
        string res1 = s.substr(left+1,right-left-1);
        left = i;
        right = i+1;
        while(left>=0 && right<s.length()){
            if(s[left]==s[right]){
                left--;
                right++;
            }
            else{
                break;
            }
        }
        string res2 = s.substr(left+1,right-left-1);
        //cout<<res1<<"   "<<res2<<endl;
        if(res1.length()>res2.length()){
            return res1;
        }
        else{
            return res2;
        }
    }
};
