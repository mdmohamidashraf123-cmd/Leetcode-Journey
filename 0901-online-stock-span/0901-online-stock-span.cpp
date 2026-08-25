class StockSpanner {
public:
    vector<int>arr;
    StockSpanner() {
                
    }
    
    int next(int price) {
        int c=1;
        int j=arr.size();
        while(j>=1 && arr[j-1]<=price){
            c++;
            j--;
        }
        arr.push_back(price);
        return c;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */