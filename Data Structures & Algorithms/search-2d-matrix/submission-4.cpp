class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int srow = 0;
        int erow = matrix.size()-1;
        if(matrix.size()==0){
            return false;
        }
        int scol = 0;
        int ecol = matrix[0].size()-1;
        int mrow = (srow + erow)/2;
        while(srow <= erow){
            mrow = (srow + erow)/2;
            if (target>=matrix[mrow][scol] && target<=matrix[mrow][ecol]){
                break;
            }
            else if(target < matrix[mrow][scol]){
                erow = mrow - 1;
            }else{
                srow = mrow + 1;
            }
        }
        while(scol <= ecol){
            int mcol = (scol + ecol)/2;
            if(matrix[mrow][mcol]==target){
                return true;
            }
            else if(matrix[mrow][mcol]<target){
                scol = mcol + 1;
            }else{
                ecol = mcol - 1;
            }
        }
        return false;
    }
};
