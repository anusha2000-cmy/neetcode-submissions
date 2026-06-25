class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generate(0,0,n,"",res);
        return res;
    }

    void generate(int i,int j,int n,string s,vector<string>& res){
        if(s.length()==2*n){
            res.push_back(s);
            return;
        }
        if(i<n){
            generate(i+1,j,n,s+"(",res);
        }
        if(j<i){
            generate(i,j+1,n,s+")",res);
        }
    }
};
