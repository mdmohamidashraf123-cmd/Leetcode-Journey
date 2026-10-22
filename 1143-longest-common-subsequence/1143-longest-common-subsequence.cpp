class Solution {
public:
    int lcs(int s1,int s2,string& text1,string& text2,vector<vector<int>>&dp){
        if(s1<0||s2<0){
            return 0;
        }
        if(dp[s1][s2]!=-1){
            return dp[s1][s2];
        }
        int c=0;
        int d=0,e=0;
        if(text1[s1]==text2[s2]){
          c=lcs(s1-1,s2-1,text1,text2,dp)+1;
        }else{
            d=lcs(s1-1,s2,text1,text2,dp);
            e=lcs(s1,s2-1,text1,text2,dp);
        }
        return dp[s1][s2]=max(d,e)+c;
    }
    int longestCommonSubsequence(string text1, string text2) {
      //using DP
      int n=text1.size();
      int m=text2.size();
      vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
      int x=lcs(n-1,m-1,text1,text2,dp);
      return x;
    }
};