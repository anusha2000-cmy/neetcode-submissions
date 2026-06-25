class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> permute(vector<int>& nums) {
        generate(nums,0,{});
        return res;
    }

    void generate(vector<int>& nums,int i,vector<int> path){
        if(i>=nums.size()){
            res.push_back(path);
            return;
        }
        for(int j=i;j<nums.size();j++){
            swap(nums[i],nums[j]);
            path.push_back(nums[i]);
            generate(nums,i+1,path);
            path.pop_back();
            swap(nums[i],nums[j]);
        }
    }
};
