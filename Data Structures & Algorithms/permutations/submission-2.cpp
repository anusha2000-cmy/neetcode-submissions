class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> permute(vector<int>& nums) {
        generate(nums,0);
        return res;
    }

    void generate(vector<int>& nums,int i){
        if(i>=nums.size()){
            res.push_back(nums);
            return;
        }
        for(int j=i;j<nums.size();j++){
            swap(nums[i],nums[j]);
            generate(nums,i+1);
            swap(nums[i],nums[j]);
        }
    }
};
