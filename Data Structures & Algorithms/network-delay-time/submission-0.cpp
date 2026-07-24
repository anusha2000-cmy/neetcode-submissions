class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,vector<pair<int,int>>> edges;
        for(auto time:times){
            edges[time[0]].push_back({time[1],time[2]});
        }
        set<int> visited;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> q;
        q.push({0,k});
        int t=0;
        while(!q.empty()){
            int t1=q.top().first;
            int node=q.top().second;
            q.pop();
            if(visited.count(node)){
                continue;
            }
            visited.insert(node);
            t=t1;
            if(edges.count(node)){
                for(auto p:edges[node]){
                    int t2=p.second;
                    int n2=p.first;
                    if(!visited.count(n2)){
                        q.push({t1+t2,n2});
                    }
                }
            }
        }
        return visited.size()==n ? t:-1;
    }
};
