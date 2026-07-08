class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        int one=digits[n-1];
        if(one!=9){
            digits[n-1]=one+1;
            
        }else{
            int carry=1;
            int i=n-2;
            digits[n-1]=0;
            while(i>=0 && carry==1){
                int k = (digits[i]+carry)/10;
                digits[i]=(digits[i]+carry)%10;
                carry = k;
                i--;
            }
            if(carry==1){
                digits.insert(digits.begin(),1);
            }
        }
        return digits;
    }
};
