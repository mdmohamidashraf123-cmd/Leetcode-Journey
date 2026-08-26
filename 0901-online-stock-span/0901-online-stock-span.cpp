class StockSpanner {
public:
    stack<pair<int,int>>st;
    int k=0;
    StockSpanner() {
                          
    }
    
    int next(int price) {
        int c=0;
        int pse=-1;
        while(!st.empty() && st.top().first <=price){
            st.pop();
        }
        if(!st.empty()){
         c+=k-st.top().second;
        }else{
            c=k-pse;
        }
        st.push({price,k});
        k++;
        return c;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */