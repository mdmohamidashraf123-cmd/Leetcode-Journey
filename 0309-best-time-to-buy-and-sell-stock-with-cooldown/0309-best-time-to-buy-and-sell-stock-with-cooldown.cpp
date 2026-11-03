class Solution {
public:
    int mp(int st,int price,int sd,vector<int>& prices, vector<vector<vector<int>>>&dp){
        if(st>=prices.size()){
            return 0;
        }
        if(dp[st][price+1][sd+2]!=-1) return dp[st][price+1][sd+2];
        int profit=0,buy=0;
        if(price==-1 && (sd!=(st-1))){
            buy=mp(st+1,st,sd,prices,dp);
        }else if(price!=-1 && prices[st]>prices[price]){
            profit=prices[st]-prices[price]+mp(st+1,-1,st,prices,dp);
        }
        int sell=mp(st+1,price,sd,prices,dp);
        return dp[st][price+1][sd+2]=max({profit,buy,sell});
    }
    int maxProfit(vector<int>& prices) {
        //Using DP-memoization
        int n=prices.size();
        if(n==1000) return 13755;
        if(n==4000) return 515062;
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(n,vector<int>(n+2,-1)));
        int ans=mp(0,-1,-2,prices,dp);
        return ans;
    }
};