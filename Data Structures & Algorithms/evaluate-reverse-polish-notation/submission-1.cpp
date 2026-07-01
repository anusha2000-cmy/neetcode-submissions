class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(string s:tokens){
            if(isdigit(s[0]) || (s[0]=='-' && isdigit(s[1]))){
                st.push(stoi(s));
            }else{
                int o1=st.top();
                st.pop();
                int o2=st.top();
                st.pop();
                if(s=="+"){
                    st.push(o1+o2);
                }
                if(s=="-"){
                    st.push(o2-o1);
                }
                if(s=="*"){
                    st.push(o1*o2);
                }
                if(s=="/"){
                    st.push(o2/o1);
                }
            }
        }
        return st.top();
    }
};
