class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        generate(nums,0,{});
        return res;
    }

    void generate(vector<int>& nums,int i,vector<int> path){
        if(i==nums.size()){
            res.push_back(path);
            return;
        }
        path.push_back(nums[i]);
        generate(nums,i+1,path);
        path.pop_back();
        while(i+1<nums.size() && nums[i]==nums[i+1]){
            i++;
        }
        generate(nums,i+1,path);
    }
};
