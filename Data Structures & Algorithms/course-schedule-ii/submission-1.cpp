class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> res;
        vector<int> indegree(numCourses,0);
        vector<vector<int>> adj(numCourses);
        for(auto v:prerequisites){
            indegree[v[1]]++;
            adj[v[0]].push_back(v[1]);
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
                res.push_back(i);
            }
        }
        int finish=0;
        while(!q.empty()){
            int k=q.front();
            q.pop();
            finish++;
            for(int v:adj[k]){
                indegree[v]--;
                if(indegree[v]==0){
                    q.push(v);
                    res.push_back(v);
                }
            }
        }
        if(finish!=numCourses){
            return {};
        }
        std::reverse(res.begin(),res.end());
        return res;
    }
};
