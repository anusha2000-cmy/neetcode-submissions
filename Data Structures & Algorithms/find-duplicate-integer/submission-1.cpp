class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int num:nums){
            int ids=abs(num)-1;
            if(nums[ids]<0)
                return abs(num);
            else{
                nums[ids]*=-1;
            }
        }
        return -1;
    }
};
