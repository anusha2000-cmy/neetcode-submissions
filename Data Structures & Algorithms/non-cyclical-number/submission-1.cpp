class Solution {
public:
    bool isHappy(int n) {
        set<int> s;
        while(!s.count(n)){
            if(n==1)
                return true;
            else
                s.insert(n);
            n = sumSquares(n);
        }
        return false;
    }

    int sumSquares(int n){
        int res=0;
        while(n>0){
            int k=n%10;
            res+=k*k;
            n/=10;
        }
        return res;
    }
};
