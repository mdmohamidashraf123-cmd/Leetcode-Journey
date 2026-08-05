class Solution {
public:
    int kthGrammar(int n, int k) {
        int a;
        if(n==1){
            return 0;
        }
        if(n==2){
            if(k==1){
                return 0;
            }else{
                return 1;
            }
        }
        if(k<=pow(2,n-2)){
          a=kthGrammar(n-1,k);
        }else{
            k-=pow(2,n-2);
            a=!(kthGrammar(n-1,k));
        }
        return a;
    }
};