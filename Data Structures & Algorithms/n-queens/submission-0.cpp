class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> grid;
        vector<string> board(n, string(n, '.'));
        solveMaze(grid,board,0);
        return grid;
    }

    void solveMaze(vector<vector<string>>& grid,vector<string>& board,int count){
        if(count==board.size()){
            grid.push_back(board);
            return;
        }
        for(int i=0;i<board.size();i++){
            if(isSafe(count,i,board)){
                board[count][i]='Q';
                solveMaze(grid,board,count+1);
                board[count][i]='.';
            }
        }
    }

    bool isSafe(int r,int c,vector<string>& grid){
        for(int i=r-1;i>=0;i--){
            if(grid[i][c]=='Q')
                return false;
        }
        for(int i=r-1,j=c-1;i>=0 && j>=0;i--,j--){
            if(grid[i][j]=='Q')
                return false;
        }
        for(int i=r-1,j=c+1;i>=0 && j<grid.size();i--,j++){
            if(grid[i][j]=='Q')
                return false;
        }
        return true;
    }
};
