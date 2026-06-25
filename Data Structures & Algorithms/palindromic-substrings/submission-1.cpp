class Solution {
private:
    int count;
public:
    int countSubstrings(string s) {
        count=0;
        int i=0;
        while(i<s.length()){
            int c=checkPalindrome(s,i);
            count+=c;
            i++;
        }
        return count;
    }

    int checkPalindrome(string s,int i){
        int n=0;
        int left=i;
        int right=i;
        //check odd

        while(left>=0 && right<s.length()){
            if(s[left]==s[right]){
                n++;
                left--;
                right++;
            }
            else{
                break;
            }
        }
        left = i;
        right = i+1;
        while(left>=0 && right<s.length()){
            if(s[left]==s[right]){
                n++;
                left--;
                right++;
            }
            else{
                break;
            }
        }
        return n;
    }
};
