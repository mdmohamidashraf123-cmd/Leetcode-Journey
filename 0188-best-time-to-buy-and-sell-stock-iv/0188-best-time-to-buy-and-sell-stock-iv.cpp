class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        //Using DP-tabulation
        int n=prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(3,vector<int>(k+1,0)));
         for(int st=n-1;st>=0;st--){
            for(int n=k-1;n>=0;n--){
                for(int buy=0;buy<2;buy++){
                  int profit=0;
                  if(buy){
                    profit=max(-prices[st]+dp[st+1][0][n],dp[st+1][1][n]);
                  }else{
                    profit=max(prices[st]+dp[st+1][1][n+1],dp[st+1][0][n]);
                  }
                  profit=max(profit,dp[st+1][buy][n]);
                  dp[st][buy][n]=profit;
                }
            }
        }
        return dp[0][1][0];
    }
};