class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char,int> m;
        for(int i=0;i<s.length();i++){
            m[s[i]]=i;
        }    
        vector<int> res;
        for(int i=0;i<s.length();i++){
            int st=i;
            int e=m[s[i]];
            int j=st+1;
            while(j<e){
                if(m[s[j]]>e){
                    e=m[s[j]];
                }
                j++;
            }
            res.push_back(e-st+1);
            i=e;
        }
        return res;
    }
};
