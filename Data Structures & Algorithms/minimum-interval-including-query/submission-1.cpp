class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(),intervals.end());
        vector<int> sq=queries;
        sort(sq.begin(),sq.end());
        map<int,int> res;

        priority_queue<vector<int>, vector<vector<int>>, decltype([](auto& a,auto& b){
            return a[0]>b[0] || (a[0]==b[0] && a[1]>b[1]);
        })> pq;
        int i=0;
        for(int q:sq){
            while(i<intervals.size() && intervals[i][0]<=q){
                int l = intervals[i][0];
                int r = intervals[i][1];
                pq.push({r-l+1,r});
                i++;
            }
            while(!pq.empty() && pq.top()[1]<q){
                pq.pop();
            }
            res[q]=pq.empty()?-1:pq.top()[0];
        }

        vector<int> r(queries.size());
        for(int i=0;i<queries.size();i++){
            r[i]=res[queries[i]];
        }
        return r;
    }
};
