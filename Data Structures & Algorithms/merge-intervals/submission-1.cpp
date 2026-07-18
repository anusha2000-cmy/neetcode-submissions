class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n=intervals.size();
        int i=0;
        vector<vector<int>> res;
        while(i<n){
            int j=i+1;
            int x=intervals[i][0];
            int y=intervals[i][1];
            while(j<n && y>=intervals[j][0]){
                x=min(x,intervals[j][0]);
                y=max(y,intervals[j][1]);
                j++;
            }
            res.push_back({x,y});
            i=j;
        }
        return res;
    }
};
