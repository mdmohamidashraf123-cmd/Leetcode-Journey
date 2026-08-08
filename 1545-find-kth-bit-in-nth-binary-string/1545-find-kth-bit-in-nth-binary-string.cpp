class Solution {
public:
    int a(int n){
        int s=1;
        int d=2;
        for(int i=0;i<n-1;i++){
            s+=d;
            d*=2;
        }
        return s;
    }
    char findKthBit(int n, int k) {
        if(n==1|| k==1){
            return '0';
        }
        int b=a(n);
        if(k==(b/2+1)){
            return '1';
        }else if(k>(b/2+1)){
            int c=k-(b/2+1);
            k=b/2+1-c;
            char x=findKthBit(n-1,k);
            if(x=='0'){
                return '1';
            }else{
                return '0';
            }
        }else{
            return findKthBit(n-1,k);
        }
    }
};