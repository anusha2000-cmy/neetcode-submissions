class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return dfs(0,nums,target);
    }

    int dfs(int i,vector<int>& nums,int target){
        if(i>=nums.size()){
            if(target==0){
                return 1;
            }
            else{
                return 0;
            }
        }
        return dfs(i+1,nums,target-nums[i])+dfs(i+1,nums,target+nums[i]);
    }
};
