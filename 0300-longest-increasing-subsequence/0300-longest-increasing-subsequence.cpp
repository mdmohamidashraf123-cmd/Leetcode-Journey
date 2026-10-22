class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        //using DP-tabulation
        //Space Optimized
        int n=nums.size();
        vector<int>dp(n+1,0);
        for(int i=n-1;i>=0;i--){
            for(int j=-1;j<n;j++){
                int take=0;
                if(j==-1||(nums[j]<nums[i])){
                    take=dp[i+1]+1;
                }
                int skip=dp[j+1];
                dp[j+1]=max(take,skip);
            }
        }
        return dp[0];
    }
};