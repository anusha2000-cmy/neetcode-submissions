class Solution {
public:
    bool isPalindrome(string s) {
        int lo=0;
        int high=s.length()-1;
        while(lo<high){
            while(!isalpha(s[lo]) && !isdigit(s[lo])){
                lo++;
            }
            while(!isalpha(s[high]) && !isdigit(s[high])){
                high--;
            }
            if(lo<=high && tolower(s[lo])!=tolower(s[high])){
                return false;
            }
            lo++;
            high--;
        }
        return true;
    }
};
