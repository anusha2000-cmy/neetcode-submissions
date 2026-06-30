class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int r=board.size();
        int c=board[0].size();
        vector<vector<bool>> connected(r,vector<bool>(c,false));

        for(int i=0;i<c;i++){
            if(board[0][i]=='O')
            dfs(0,i,board,connected);
            if(board[r-1][i]=='O')
            dfs(r-1,i,board,connected);
        }

        for(int i=0;i<r;i++){
            if(board[i][0]=='O')
            dfs(i,0,board,connected);
            if(board[i][c-1]=='O')
            dfs(i,c-1,board,connected);
        }

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(!connected[i][j])
                    board[i][j]='X';
            }
        }

    }

    void dfs(int r,int c,vector<vector<char>>& heights,vector<vector<bool>>& connected){
        connected[r][c]=true;
        int rows[4]={0,0,1,-1};
        int cols[4]={1,-1,0,0};
        for(int i=0;i<4;i++){
            int r1=r+rows[i];
            int c1=c+cols[i];
            if(r1>=0 && r1<heights.size() && c1>=0 && c1<heights[0].size() && !connected[r1][c1] &&
                heights[r1][c1]=='O'){
                    dfs(r1,c1,heights,connected);
                
                }
            else{
                continue;
            }

        }
    }


};
