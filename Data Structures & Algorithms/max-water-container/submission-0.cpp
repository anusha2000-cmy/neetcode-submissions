class Solution {
public:
    int maxArea(vector<int>& heights) {
        int lo=0;
        int hi=heights.size()-1;
        int m=0;
        while(lo<hi){
            m = max(m,min(heights[lo],heights[hi])*(hi-lo));
            if(heights[lo]<heights[hi]){
                lo++;
            }
            else{
                hi--;
            }
        }
        return m;
    }
};
