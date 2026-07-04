class Solution {
public:
    int hammingWeight(int n) {
        int binform=n;
        int c=0;
        while(binform>0){
            int rem=binform%2;
            if(rem==1){
             c++;
            }
            binform/=2;
        }
        return c;
    }
};