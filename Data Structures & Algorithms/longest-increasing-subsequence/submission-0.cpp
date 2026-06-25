class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> LIS(nums.size(),1);
        int maxi=1;
        for(int i=nums.size()-2;i>=0;i--){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]<nums[j]){
                    LIS[i] = max(LIS[i],1+LIS[j]);
                }
            }
            maxi = max(maxi,LIS[i]);
        }
        return maxi;
    }
};
