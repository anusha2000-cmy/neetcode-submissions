class Solution {
public:
    int findMin(vector<int> &nums) {
        int l=0;
        int h=nums.size()-1;
        int res = nums[0];
        while(l<=h){
            if(nums[l]<nums[h]){
                return nums[l];
            }
            int mid = (l + h)/2;
            res = nums[mid];
            if(nums[l]<=nums[mid]){
                l = mid+1;
            }
            else{
                h=mid;
            }
        }
        return res;
    }
};
