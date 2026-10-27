class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n=dungeon.size();
        int m=dungeon[0].size();
        if(n==1 && m==1){
            return dungeon[0][0]>=0 ?1:1-dungeon[0][0];
        }
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        fill(dp[n].begin(),dp[n].end(),1e9);
        for(int i=0;i<n;i++){
            dp[i][m]=1e9;
        }
        dp[n-1][m-1]= max(1, 1 - dungeon[n-1][m-1]);
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(i==n-1 && j==m-1) continue;
                int right=dp[i][j+1];
                int down=dp[i+1][j];
                dp[i][j]=max(1,(min(right,down)-dungeon[i][j]));
            }
        }
        return dp[0][0];
    }
};