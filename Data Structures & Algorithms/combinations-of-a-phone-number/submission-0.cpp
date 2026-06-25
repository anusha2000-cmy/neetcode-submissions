class Solution {
public:
    unordered_map<char,string> m;
    vector<string> res;
    vector<string> letterCombinations(string digits) {
        m['2'] = "abc";
        m['3']="def";
        m['4']="ghi";
        m['5']="jkl";
        m['6']="mno";
        m['7']="pqrs";
        m['8']="tuv";
        m['9']="wxyz";
        if(digits.length()==0){
            return res;
        }
        dfs(digits,0,"");
        return res;
    }

    void dfs(string& digits,int i,string s){
        if(i==digits.length()){
            res.push_back(s);
            return;
        }
        string st=m[digits[i]];
        for(int j=0;j<st.length();j++){
            dfs(digits,i+1,s+st[j]);
        }
    }
};
