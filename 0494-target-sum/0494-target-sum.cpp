class Solution {
public:
    int  fts(int st,vector<int>&nums,int target,vector<unordered_map<int, int>>&dp){
        if(st==nums.size() && target==0){
            return 1;
        }
        if(st==nums.size()){
            return 0;
        }
        if(dp[st].count(target)){
            return dp[st][target];
        }
        int c=fts(st+1,nums,target-nums[st],dp);
        int d=fts(st+1,nums,target+nums[st],dp);
        dp[st][target]=c+d;
        return c+d;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
      //using DP-memoization
      //using a vector of unordered maps
       int n=nums.size();
       vector<unordered_map<int, int>> dp(nums.size());
       int a=fts(0,nums,target,dp);
       return a;
    }
};