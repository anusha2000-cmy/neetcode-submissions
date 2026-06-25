class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0];
        int curMin = 1, curMax = 1;
        for(int num:nums){
            int t = num*curMax;
            curMax = max(max(num,t),num*curMin);
            curMin = min(min(num,num*curMin),t);
            res = max(res, curMax);
        }
        return res;
    }
};
