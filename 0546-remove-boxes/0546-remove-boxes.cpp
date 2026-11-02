class Solution {
public:
    int removeBoxes(vector<int>& boxes) {
        //Using DP-tabulation
        int n=boxes.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(n+1,vector<int>(n+1000,0)));
        for(int st=n-1;st>=0;st--){
          for(int end=st;end<n;end++){
            for(int k=0;k<n;k++){
               if(st>end) continue;
               int i = st;
               int run_k = k;
               while (i + 1 <= end && boxes[i + 1] == boxes[st]) {
                  run_k++;
                  i++;
               }
               int ans=(run_k + 1) * (run_k + 1) +dp[i+1][end][0];
               for(int j=i+1;j<=end;j++){
                  if(boxes[j]==boxes[st]){
                    ans=max(ans,dp[i+1][j-1][0]+dp[j][end][run_k+1]);
                  }
                }
                dp[st][end][k]=ans;
            }
          }
        }
        int ans=dp[0][n-1][0];
        
        return ans;
    }
};