class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        dfs(candidates,0,target,{});
        return res;
    }

    void dfs(vector<int>& candidates, int i,int target,vector<int> temp){
        if(target==0){
            res.push_back(temp);
            return;
        }
        if(target<0 || i>=candidates.size()){
            return;
        }
        temp.push_back(candidates[i]);
        dfs(candidates,i+1,target-candidates[i],temp);
        temp.pop_back();
        while(i+1<candidates.size() && candidates[i]==candidates[i+1] ){
            i++;
        }
        dfs(candidates,i+1,target,temp);
    }

};
