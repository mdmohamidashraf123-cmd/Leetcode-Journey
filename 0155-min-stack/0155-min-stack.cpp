class MinStack {
private:
    stack<long long>st;
    long long  min=INT_MAX;
public:
    MinStack() {
    }
    
    void push(int val) {
        if(st.empty()){
          min=val;
          st.push(val);
        }else{
            if(min<val){
                st.push(val);
            }else{
                long long newval=2LL*val-min;
                min=val;
                st.push(newval);
            }
        }
    }
    void pop() {
        if(st.empty()){
            return;
        }
        if(min>st.top()){
            int m=2*min-st.top();
            min=m;
            st.pop();
        }else{
            st.pop();
        }
    }
    int top() {
        if(min<st.top()){
            return st.top();
        }else{
            return min;
        }
    }
    int getMin() {
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */