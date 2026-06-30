class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int r=board.size();
        int c=board[0].size();

        for(int i=0;i<c;i++){
            if(board[0][i]=='O')
            dfs(0,i,board);
            if(board[r-1][i]=='O')
            dfs(r-1,i,board);
        }

        for(int i=0;i<r;i++){
            if(board[i][0]=='O')
            dfs(i,0,board);
            if(board[i][c-1]=='O')
            dfs(i,c-1,board);
        }

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(board[i][j]=='O')
                    board[i][j]='X';
                if(board[i][j]=='T')
                    board[i][j]='O';
            }
        }

    }

    void dfs(int r,int c,vector<vector<char>>& heights){
        heights[r][c]='T';
        int rows[4]={0,0,1,-1};
        int cols[4]={1,-1,0,0};
        for(int i=0;i<4;i++){
            int r1=r+rows[i];
            int c1=c+cols[i];
            if(r1>=0 && r1<heights.size() && c1>=0 && c1<heights[0].size() &&
                heights[r1][c1]=='O'){
                    dfs(r1,c1,heights);
                
                }
            else{
                continue;
            }

        }
    }


};
