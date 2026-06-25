class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        generate(nums,0,temp,ans);
        return ans;
    }

    void generate(vector<int>& nums,int i,vector<int> temp,vector<vector<int>>& ans){
        if(i==nums.size()){
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[i]);
        generate(nums,i+1,temp,ans);
        temp.pop_back();
        generate(nums,i+1,temp,ans);
    }
};
