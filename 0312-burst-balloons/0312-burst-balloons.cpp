class Solution {
public:
    int solve(int i,int j,vector<int>&nums,vector<vector<int>>& dp){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int maxi=-1e8;
        for(int k=i;k<=j;k++){
            int m=nums[i-1]*nums[k]*nums[j+1]+solve(i,k-1,nums,dp)+solve(k+1,j,nums,dp);
            maxi=max(maxi,m);
        }
        return dp[i][j]=maxi;
    }
    int maxCoins(vector<int>& nums) {
        //Using DP-memoization
        int n=nums.size();
        vector<int>a=nums;
        a.push_back(1);
        a.insert(a.begin(),1);
        vector<vector<int>>dp(n+2,vector<int>(n+2,-1));
        return solve(1,n,a,dp);
    
    }
};