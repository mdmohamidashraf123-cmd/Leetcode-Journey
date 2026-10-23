class Solution {
public:
    int minDistance(string word1, string word2) {
        //Using DP-tabulation-Space Optimized
        int n=word1.size();
        int m=word2.size();
        vector<int>prev(m+1,0);
        for(int i=m;i>=0;i--){
            prev[i]=m-i;
        }
        for(int i=n-1;i>=0;i--){
            vector<int>curr(m+1,0);
            curr[m]=n-i;
            for(int j=m-1;j>=0;j--){
                int k=INT_MAX,d=0,e=0,f=0;
                if(word1[i]==word2[j]){
                    k=prev[j+1];
                    curr[j]=k;
                }else{
                    d=prev[j+1]+1;
                    f=curr[j+1]+1;
                    e=prev[j]+1;
                    curr[j]=min({d,e,f});
                }
            }
            prev=curr;
        }
        return prev[0];
    }
};