class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> n;
        for(int i=0;i<nums.size();i++){
            if(n.contains(nums[i]))
                return true;
            n.insert(nums[i]);
        }
        return false;
    }
};