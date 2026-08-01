class Solution {
public:
    int reverse(int x) {
        int rev=0;
        if(x==INT_MIN || x==INT_MAX){
            return 0;
        }
        if(x>INT_MIN && x<(-(INT_MAX))){
            return 0;
        }
        while(x!=0){
            int rem=x%10;
            if(rev>INT_MAX/10||(rev==INT_MAX/10 && rem>7) || rev<INT_MIN/10 ||(rev==INT_MIN/10 && rem<-8)){
              return 0;
            }
            rev=rev*10+rem;
            x/=10;
        }
        return rev;
    }
};