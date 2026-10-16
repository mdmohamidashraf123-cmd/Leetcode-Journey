class Solution {
public:
    int climbStairs(int n) {
        if(n==1||n==2){
            return n;
        }
        //using DP-tabulation
        int prev=1;
        int pre=2;
        for(int i=3;i<=n;i++){
           int curr=prev+pre;
           prev=pre;
           pre=curr;
           
        }
        return pre;
    }
};