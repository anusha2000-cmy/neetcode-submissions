class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            unordered_set<char> s;
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    continue;
                }else if(s.contains(board[i][j])){
                    return false;
                }else{
                    s.insert(board[i][j]);
                }
            }
        }
        for(int i=0;i<9;i++){
            unordered_set<char> s;
            for(int j=0;j<9;j++){
                if(board[j][i]=='.'){
                    //do nothing
                }
                else if(s.contains(board[j][i])){
                    return false;
                }else{
                    s.insert(board[j][i]);
                }
            }
        }
        for (int square = 0; square < 9; square++) {
            unordered_set<char> seen;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    int row = (square / 3) * 3 + i;
                    int col = (square % 3) * 3 + j;
                    if (board[row][col] == '.') continue;
                    if (seen.count(board[row][col])) return false;
                    seen.insert(board[row][col]);
                }
            }
        }
        return true;
    }
};
