class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> grid(m,vector<int>(n,-1));
        grid[m-1][n-1]=1;
        return findPath(0,0,m,n,grid);
    }

    int findPath(int i,int j,int m,int n,vector<vector<int>>& grid){
        if(i<0 || i>=m || j<0 || j>=n){
            return 0;
        }
        if(grid[i][j]!=-1){
            return grid[i][j];
        }
        return grid[i][j] = findPath(i+1,j,m,n,grid) + findPath(i,j+1,m,n,grid);
    }
};
