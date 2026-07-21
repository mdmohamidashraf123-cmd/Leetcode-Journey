class Solution {
public:
    void calculate(long long b,double x,double& ans){
        if(b==0){
          return; 
        }
        if(b%2==1){
            ans*=x;
        }
        x*=x;
        calculate(b/2,x,ans);
    }
    double myPow(double x, int n) {
       double ans=1;
       long long binform=n;
        if (binform<0) {
            x=1/x;
            binform=-(binform);
        }
        calculate(binform,x,ans);
        return ans;
    }
};