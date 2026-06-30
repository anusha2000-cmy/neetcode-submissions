class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==0)
                    q.push({i,j});
            }
        }

        int rows[4] = {0,0,1,-1};
        int cols[4] = {1,-1,0,0};

        while(!q.empty()){
            int r1=q.front().first;
            int c1=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int row=r1+rows[i];
                int col=c1+cols[i];
                if(row<0 || col<0 || row>=r || col>=c || grid[row][col]!=INT_MAX)
                    continue;
                else{
                    grid[row][col]=1+grid[r1][c1];
                    q.push({row,col});
                }
            }
        }
    }

    
};
