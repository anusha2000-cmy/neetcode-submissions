class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char& c:s){
            if(c=='(' || c=='{' || c=='[')
                st.push(c);
            else{
                if(!st.empty()){
                char c1=st.top();
                st.pop();
                if((c==')' && c1=='(') || (c=='}' && c1=='{') || (c==']' && c1=='[')){
                    continue;
                }
                else{
                    return false;
                }
                }else{
                    return false;
                }
            }
        }
        return st.empty();
    }
};
