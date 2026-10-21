class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int sum = 0;
        for(int x : stones) {
            sum += x;
        }
        
        int target = sum / 2;
        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));
        
        // Base case: a subset sum of 0 is always possible
        for(int i = 0; i <= n; i++) {
            dp[i][0] = true;
        }
        
        // Fill the DP table from bottom to top
        for(int i = n - 1; i >= 0; i--) {
            for(int j = 0; j <= target; j++) {
                bool skip = dp[i + 1][j];
                bool take = false;
                if(stones[i] <= j) {
                    take = dp[i + 1][j - stones[i]];
                }
                dp[i][j] = (take || skip);
            }
        }
        
        // Find the largest achievable subset sum <= target
        int max_subset_sum = 0;
        for(int j = target; j >= 0; j--) {
            if(dp[0][j]) {
                max_subset_sum = j;
                break;
            }
        }
        
        return sum - 2 * max_subset_sum;
    }
};