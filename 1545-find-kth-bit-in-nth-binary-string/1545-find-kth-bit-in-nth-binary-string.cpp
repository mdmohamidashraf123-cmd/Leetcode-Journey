class Solution {
public:
    char findKthBit(int n, int k) {
        if(n==1|| k==1){
            return '0';
        }
        int b=(1<<n)-1;
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