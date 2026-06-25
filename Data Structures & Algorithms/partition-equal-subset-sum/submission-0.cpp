class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum =0;
        for(int num:nums){
            sum+=num;
        }
        if(sum%2!=0){
            return false;
        }
        return checksum(nums,0,sum/2);
    }

    bool checksum(vector<int>& nums,int i,int target){
        if(target==0){
            return true;
        }
        if(i==nums.size() || target<0){
            return false;
        }
        return checksum(nums,i+1,target-nums[i]) || checksum(nums,i+1,target);
    }
};
