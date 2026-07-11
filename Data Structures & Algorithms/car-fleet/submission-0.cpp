class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> p;
        for(int i=0;i<position.size();i++){
            p.push_back({position[i],speed[i]});
        }
        sort(p.rbegin(),p.rend());
        vector<double> st;
        for(auto pp:p){
            st.push_back((double)(target-pp.first)/pp.second);
            if(st.size()>=2 && st.back()<=st[st.size()-2])
                st.pop_back();
        }
        return st.size();
    }
};
