class Solution {
public:
    //Intuituon-Since a plaindrome is a string read same from front and end Therefore you can see the problem as finding the lcs between string and its reverse 
    int longestCommonSubsequence(string text1, string text2) {
      //using DP-tabulation-Space Optimized
      int n=text1.size();
      int m=text2.size();
      vector<int>dp(m+1,0),curr(m+1,0);
      for(int i=1;i<=n;i++){
        int prev=0;
        for(int j=1;j<=m;j++){
            int temp=dp[j];
            if(text1[i-1]==text2[j-1]){
               int c=prev+1;
                dp[j]=c;
            }else{
                int d=dp[j];
                int e=dp[j-1];
                dp[j]=max(d,e);
            }
            prev=temp;  
        }
      }
      return dp[m];
    }
    int longestPalindromeSubseq(string s) {
        //using DP-Tabulation
        //Space Optimized
        string k=string(s.rbegin(),s.rend());
        return longestCommonSubsequence(s,k);
    }
};