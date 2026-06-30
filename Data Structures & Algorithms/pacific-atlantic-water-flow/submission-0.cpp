class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> res;
        int r=heights.size();
        int c=heights[0].size();
        vector<vector<bool>> pacific(r,vector<bool>(c,false));
        vector<vector<bool>> atlantic(r,vector<bool>(c,false));

        for(int i=0;i<c;i++){
            dfs(0,i,heights,pacific);
            dfs(r-1,i,heights,atlantic);
        }

        for(int i=0;i<r;i++){
            dfs(i,0,heights,pacific);
            dfs(i,c-1,heights,atlantic);
        }

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(pacific[i][j] && atlantic[i][j]){
                    res.push_back({i,j});
                }
            }
        }

        return res;

        
    }

    void dfs(int r,int c,vector<vector<int>>& heights, vector<vector<bool>>& s){
        s[r][c]=true;
        int rows[4]={0,0,1,-1};
        int cols[4]={1,-1,0,0};
        for(int i=0;i<4;i++){
            int r1=r+rows[i];
            int c1=c+cols[i];
            if(r1>=0 && r1<heights.size() && c1>=0 && c1<heights[0].size() && !s[r1][c1] &&
                heights[r1][c1]>=heights[r][c] ){
                    s[r1][c1]=true;
                    dfs(r1,c1,heights,s);
                
                }
            else{
                continue;
            }

        }
    }
};
