class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
          
        int maxIndex=-1;
        int maxi=INT_MIN;
        int l=0;
        for(int r=k-1;r<nums.size();r++){
            if(maxIndex<l){
                maxi=INT_MIN;
                for(int j=l;j<=r;j++){
                    if(nums[j]>=maxi){
                        maxIndex=j;
                        maxi=nums[j];
                    }      
                }
            }else{
                if(nums[r]>=maxi){
                    maxIndex=r;
                    maxi=nums[r];
                }
            }
            res.push_back(maxi);
            l++;

        }
        return res;

    }
};
