class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==0){
            return false;
        }
        if(n==1){
            return true;
        }
        int rem=n%2;
        if(rem!=0){
          return false;
        }
        bool a=isPowerOfTwo(n/2);
        return a;
    }
};