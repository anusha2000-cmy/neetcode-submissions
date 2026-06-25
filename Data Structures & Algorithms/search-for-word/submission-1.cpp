class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int r = 0; r < board.size(); r++) {
            for (int c = 0; c < board[0].size(); c++) {
                if (dfs(r, c, 0,board,word)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool dfs(int i,int j,int w,vector<vector<char>>& board,string& word){
        if(w==word.length()){
            return true;
        }
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || board[i][j]!=word[w]){
            return false;
        }
        if(board[i][j] != 0){
            char temp=board[i][j];
            board[i][j]=0;
            bool res=false;
            if(temp==word[w]){
                res = dfs(i+1,j,w+1,board,word) || dfs(i-1,j,w+1,board,word) || dfs(i,j-1,w+1,board,word)
                        || dfs(i,j+1,w+1,board,word);
            }
            board[i][j]=temp;
            return res;
        }else{
            return false;
        }
    }
};
