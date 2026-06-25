class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        generate(nums,0,target,temp,ans);
        return ans;
    }

    void generate(vector<int>& nums, int i,int target,vector<int> temp,vector<vector<int>>& ans){
        if(target==0){
            for(int x:temp)
                cout<<x;
            ans.push_back(temp);
            return;
        }
        if(i==nums.size()){
            return;
        }
        if(nums[i]<=target){
            temp.push_back(nums[i]);
            generate(nums,i,target-nums[i],temp,ans);
            temp.pop_back();
        }
        generate(nums,i+1,target,temp,ans);
    }
};
