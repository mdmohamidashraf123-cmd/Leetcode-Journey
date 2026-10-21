class Solution {
public:
    bool ispossible(int st,int sum1,int sum2,vector<int>& nums,vector<vector<pair<int,bool>>>&dp){
        if(st>=nums.size()){
            return sum1==sum2;
        }
        if(dp[st][sum1].first!=-1){
            return dp[st][sum1].second;
        }
        bool c=ispossible(st+1,sum1+nums[st],sum2,nums,dp);
        bool d=ispossible(st+1,sum1,sum2+nums[st],nums,dp);
        dp[st][sum1]={0,(c||d)};
        return c||d ;
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        //using DP-memoization
        int sum=0;
        for(int i=0;i<n;i++){
           sum+=nums[i];
        }
        vector<vector<pair<int,bool>>>dp(n+1,vector<pair<int,bool>>(sum+1,{-1,false}));
        return ispossible(0,0,0,nums,dp);
    }
};