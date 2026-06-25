class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        int p=1;
        int count=0;
        for(int num:nums){
            if(num==0){
                count++;
            }else{
                p*=num;
            }
        }
        if(count>1){
            return vector<int>(n,0);
        }
        else if(count==1){
            vector<int> res;
            for(int num:nums){
                if(num==0){
                    res.push_back(p);
                }else{
                    res.push_back(0);
                }
            }
            return res;
        }
        else{
            vector<int> res;
            for(int num:nums){
                res.push_back(p/num);
            }
            return res;
        }
    }
};
