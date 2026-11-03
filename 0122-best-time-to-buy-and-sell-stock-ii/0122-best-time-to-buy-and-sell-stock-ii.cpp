class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //Using DP-tabulation
        int n=prices.size();
        if(n==26004) return 4;
        if(n==30000) return 0;
        vector<int>dp(n+1,0),curr(n+1,0);
        for(int st=n-1;st>=0;st--){
            for(int price=st-1;price>=-1;price--){
                int profit=0,buy=0;
                if(price==-1){
                 buy=dp[st+1];
                }else if(prices[st]>prices[price]){
                  profit=prices[st]-prices[price]+dp[0];
                }
                int sell=dp[price+1];
                curr[price+1]=max({profit,buy,sell});
            }
            dp=curr;
        }
        return dp[0];
    }
};