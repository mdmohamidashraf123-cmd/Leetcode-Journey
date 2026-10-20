class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        //using DP-tabulation
        int sum=0;
        for(int i=0;i<n;i++){
           sum+=nums[i];
        }
        if(sum%2==1){
            return false;
        }
        vector<vector<bool>>dp(n+1,vector<bool>(sum/2+1,false));
        dp[n-1][0]=true;
        if(nums[n-1]<=sum/2){
            dp[n-1][nums[n-1]]=true;
        }
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<=sum/2;j++){
                bool take=false;
                if(j>=nums[i]){
                 take=dp[i+1][j-nums[i]];
                }
                bool skip=dp[i+1][j];
                dp[i][j]=(take||skip);
            }
        }
        bool ans=dp[0][sum/2];
        return ans;
    }
};