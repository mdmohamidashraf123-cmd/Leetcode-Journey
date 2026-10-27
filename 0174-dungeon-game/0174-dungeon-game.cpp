class Solution {
public:
    int cmhp(int row, int col, int n, int m, vector<vector<int>>& dungeon, vector<vector<int>>& dp) {
        if (row >= n || col >= m) {
            return 1e9;
        }
        if (row == n - 1 && col == m - 1) {
            return max(1, 1 - dungeon[row][col]);
        }
        if (dp[row][col] != -1) {
            return dp[row][col];
        }
        
        int right = cmhp(row, col + 1, n, m, dungeon, dp);
        int down = cmhp(row + 1, col, n, m, dungeon, dp);
        
        return dp[row][col] = max(1, min(right, down) - dungeon[row][col]);
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        // we will go from dungeon[n-1][n-1];
        int n=dungeon.size();
        int m=dungeon[0].size();
        if(n==1 && m==1){
            return dungeon[0][0]>=0 ?1:1-dungeon[0][0];
        }

        vector<vector<int>>dp(n,vector<int>(m,-1));
        int minhealth=cmhp(0,0,n,m,dungeon,dp);
        return minhealth;
    }
};