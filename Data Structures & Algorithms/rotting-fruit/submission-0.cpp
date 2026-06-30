class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        int count=0;
        queue<pair<int,int>> q;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==2)
                    q.push({i,j});
            }
        }
        
        int rows[4] = {0,0,1,-1};
        int cols[4] = {1,-1,0,0};

        while(!q.empty()){
            int n=q.size();
        
            bool hasRotten=false;
            for(int k=1;k<=n;k++){
                int r1=q.front().first;
                int c1=q.front().second;
                q.pop();
                for(int i=0;i<4;i++){
                    int row=r1+rows[i];
                    int col=c1+cols[i];
                    if(row<0 || col<0 || row>=r || col>=c || grid[row][col]!=1)
                        continue;
                    else{
                        grid[row][col]=2;
                        q.push({row,col});
                        hasRotten = true;
                    }
                }
            }
            if(hasRotten) count++;
        }

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==1)
                    return -1;
            }
        }
        return count;
    }
};
