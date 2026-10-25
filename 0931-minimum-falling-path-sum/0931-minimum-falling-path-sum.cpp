class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        //Using DP-tabulation
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        int ans=INT_MAX;
        for(int row=n-1;row>=0;row--){
            for(int col=m-1;col>=0;col--){
               int drow[]={1,1,1};
               int dcol[]={0,-1,1};
               int mini=INT_MAX;
               for(int i=0;i<3;i++){
                  int nrow=row+drow[i];
                  int ncol=col+dcol[i];
                  if(nrow<0||nrow>=matrix.size()||ncol<0||ncol>=matrix.size()) continue;
                  int take=dp[nrow][ncol]+matrix[row][col];
                  mini=min(mini,take);
                }
                dp[row][col]= mini==INT_MAX?matrix[row][col]:mini;
            }
        }
        for(int i=0;i<m;i++){
            ans=min(ans,dp[0][i]);
        }
        return ans;
    }
};