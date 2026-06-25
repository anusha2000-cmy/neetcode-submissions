class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int,int> m;
        for(int n:nums){
            if(m.contains(n)){
                m[n]+=1;
            }else{
                m[n]=1;
            }
        }
        priority_queue<pair<int,int>> pq;
        for(auto [a,b]:m){
            pq.push({b,a});
        }
        for(int i=0;i<k;i++){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
