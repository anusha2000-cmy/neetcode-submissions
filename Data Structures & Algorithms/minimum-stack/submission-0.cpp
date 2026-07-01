class MinStack {
private:
    vector<int> st;
    int minimum;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()){
            minimum=val;
        }else{
            minimum=min(minimum,val);
        }
        st.push_back(val);
    }
    
    void pop() {
        st.pop_back();
        minimum=INT_MAX;
        for(int i:st){
            minimum=min(minimum,i);
        }
    }
    
    int top() {
        return st.back();
    }
    
    int getMin() {
        return minimum;
    }
};
