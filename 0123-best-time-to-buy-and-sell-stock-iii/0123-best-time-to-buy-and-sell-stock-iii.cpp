class Solution {
public:
    int f(int st,int buy,int n,vector<int>& prices,vector<vector<vector<int>>>&dp){
       if(st>=prices.size()||n==2){
        return 0;
       }
       if(dp[st][buy][n]!=-1) return dp[st][buy][n];
       int profit=0;
       if(buy){
         profit=max(-prices[st]+f(st+1,0,n,prices,dp),f(st+1,1,n,prices,dp));
       }else{
         profit=max(prices[st]+f(st+1,1,n+1,prices,dp),f(st+1,0,n,prices,dp));
       }
       profit=max(profit,f(st+1,buy,n,prices,dp));
       return dp[st][buy][n]=profit;
    }
    int maxProfit(vector<int>& prices) {
        //Using DP-Memoization
        int n=prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(2,-1)));
        return f(0,1,0,prices,dp);
    }
};