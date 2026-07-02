class Solution {
    unordered_set<int> cycle;
    int cycleStart;
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<vector<int>> adj(n+1);
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<bool> visited(n+1,false);
        cycleStart=-1;
        dfs(1,adj,-1,visited);
        for(int i=edges.size()-1;i>=0;i--){
            if(cycle.count(edges[i][0]) && cycle.count(edges[i][1]))
                return {edges[i][0],edges[i][1]};
        }
        return {};
    }

    bool dfs(int i,vector<vector<int>>& adj,int parent,vector<bool>& visited){
        if(visited[i]){
            cycleStart=i;
            return true;
        }
        visited[i]=true;
        for(int v:adj[i]){
            if(v==parent)
                continue;
            if(dfs(v,adj,i,visited)){
                if(cycleStart != -1){
                    cycle.insert(i);
                }
                if(i==cycleStart){
                    cycleStart = -1;
                }
                return true;
            }
        }
        return false;
    }
};
