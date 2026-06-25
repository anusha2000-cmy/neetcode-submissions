class Solution {
public:
    int dfs(vector<vector<int>>& grid,int r,int c){
        int n=grid.size();
        int m=grid[0].size();
        int rows[4] = {0,0,1,-1};
        int cols[4] = {1,-1,0,0};
        grid[r][c] = 0;
        int res = 0;
        for(int i=0;i<4;i++){
            int rw = r+rows[i];
            int cw = c+cols[i];
            if(rw<0 || rw>=n || cw<0 || cw>=m || grid[rw][cw]==0)
                continue;
            else
                res+=dfs(grid,rw,cw);
        }
        return 1+res;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        int islands=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==1){
                    islands = max(islands,dfs(grid,i,j));
                }
            }
        }
        return islands;
    }
};
