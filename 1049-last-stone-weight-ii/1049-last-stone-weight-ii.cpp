class Solution {
public:
    int lsw(int st,int curr_sum,int sum2,vector<int>& stones,vector<vector<int>>&dp){
        if(st>=stones.size()){
            int a=sum2-curr_sum;
            return abs(a);
        }
        if(dp[st][curr_sum]!=-1){
            return dp[st][curr_sum];
        }
        int take=lsw(st+1,curr_sum+stones[st],sum2,stones,dp);
        int leave=lsw(st+1,curr_sum,sum2+stones[st],stones,dp);
        return dp[st][curr_sum]=min(take,leave);
    }
    int lastStoneWeightII(vector<int>& stones) {
        //using DP-memoization
        int n=stones.size();
       int ans=0;
       int sum=0;
       for(int i=0;i<n;i++){
        sum+=stones[i];
       }
       vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
       ans=lsw(0,0,0,stones,dp);
       return ans;
    }
};