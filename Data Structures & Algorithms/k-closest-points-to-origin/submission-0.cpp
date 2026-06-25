class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double,vector<int>>> q;
        for(auto i:points){
            double dist=sqrt(i[0]*i[0]+i[1]*i[1]);
            q.push({dist,i});
            if(q.size()>k){
                q.pop();
            }
        }
        vector<vector<int>> res;
        while(!q.empty()){
            res.push_back(q.top().second);
            q.pop();
        }
        return res;
    }
};
