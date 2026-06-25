class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> map;
        for(string s:strs){
            string temp = s;
            sort(s.begin(),s.end());
            if(map.count(s)){
                map[s].push_back(temp);
            }
            else{
                map[s]={temp};
            }
        }
        vector<vector<string>> res;
        for(const auto& [k,v]:map){
            res.push_back(v);
        }
        return res;
    }
};
