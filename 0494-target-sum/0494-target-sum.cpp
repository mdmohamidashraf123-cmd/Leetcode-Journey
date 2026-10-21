class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
      //using DP-tabulation -SPACE OTPIMIZED
      //abs(s-2s1)==target
      //p be the s1;
      //p=target+s/2//
       int n=nums.size();
       int sum=0;
       for(int i=0;i<n;i++){
          sum+=nums[i];
       }
       if((abs(target)>sum)||((target+sum)%2!=0)){
           return 0;
       }
       int p=(target+sum)/2;
       vector<int>dp(p+1,0);
       for (int j = 0; j <= p; j++) {
        if (j == 0) {
        // Sum 0 can always be formed by skipping. 
        // If nums[n-1] is also 0, taking it gives an extra way (total 2).
         dp[j] = (nums[n-1] == 0) ? 2 : 1;
        } else if (nums[n-1] == j) {
          dp[j] = 1;
        } else {
          dp[j] = 0;
        }
       } 
       for(int i=n-2;i>=0;i--){
        for(int j=p;j>=0;j--){
            int take=0;
            if(nums[i]<=j){
             take=dp[j-nums[i]];
            }
            int skip=dp[j];
            dp[j]=(take+skip);
        }
       }
       int c=dp[p];
       return c;
    }
};