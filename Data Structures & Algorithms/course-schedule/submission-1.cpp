class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto v:prerequisites){
            adj[v[0]].push_back(v[1]);
        }

        vector<bool> visit(numCourses,false);
        for(int i=0;i<numCourses;i++){
            if(isCycle(adj,i,visit))
                return false;
        }
        return true;
    }

    bool isCycle(vector<vector<int>>& adj,int i,vector<bool>& visit){
        
        if(visit[i])
            return true;

        visit[i] = true;

        for(int v:adj[i]){
            if(isCycle(adj,v,visit))
                return true;
        }

        visit[i] = false;
        return false;
    }
};
