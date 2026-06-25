class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int max = piles[0];
        for(int pile:piles){
            if(pile>max){
                max = pile;
            }
        }
        int l=1;
        int res = max;
        while(l<=max){
            int k = (l+max)/2;
            int hours=0;
            for(int pile:piles){
                hours+=ceil(static_cast<double>(pile)/k);
            }
            if(hours<=h){
                res = k;
                max = k-1;
            }else{
                l = k+1;
            }
        }
        return res;
    }
};
