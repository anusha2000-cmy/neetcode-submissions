class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<bool> visited(n,false);
        
        if(isCyclic(adj,0,-1,visited)){
            return false;
        }
        for(bool visit:visited){
            if(!visit)
                return false;
        }
            
        return true;
    }

    bool isCyclic(vector<vector<int>>& adj, int i,int parent,vector<bool>& visited){
        visited[i]=true;

        for(int v:adj[i]){
            if(!visited[v]){
                if(isCyclic(adj,v,i,visited)){
                    return true;
                }
            }
            else if(v!=parent)
                return true;
        }
        return false;
    }
};
