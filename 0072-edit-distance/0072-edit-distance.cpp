class Solution {
public:
    int minDistance(string word1, string word2) {
        //Using DP-tabulation
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=n;i>=0;i--){
            dp[i][m]=n-i;
        }
        for(int i=m;i>=0;i--){
            dp[n][i]=m-i;
        }
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                int k=INT_MAX,d=0,e=0,f=0;
                if(word1[i]==word2[j]){
                    k=dp[i+1][j+1];
                    dp[i][j]=k;
                }else{
                    d=dp[i+1][j+1]+1;
                    e=dp[i+1][j]+1;
                    f=dp[i][j+1]+1;
                    dp[i][j]=min({d,e,f});
                }
                
            }
        }
        return dp[0][0];
    }
};