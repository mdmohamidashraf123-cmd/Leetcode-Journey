class Solution {
public:
    int lot(int st,int back,vector<int>&nums,vector<vector<int>>&dp){
        if(st>=nums.size()){
            return 0;
        }
        if(dp[st][back+1]!=-1){
            return dp[st][back+1];
        }
        int take=0;
        if((back==-1)||(nums[st]>nums[back])){
         take=lot(st+1,st,nums,dp)+1;
        }
        int skip=lot(st+1,back,nums,dp);
        return dp[st][back+1]=max(take,skip);

    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        int ans=lot(0,-1,nums,dp);
        return ans;
    }
};