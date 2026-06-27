class Solution {
public:
    string largestOddNumber(string num) {
        int n=num.size();
        if(n==1){
            if((num[0]-'0')%2!=0){
                return num;
            }else{
                return "";
            }
        }
        string s;
        int k;
        for(int i=n-1;i>=0;i--){
            if((num[i]-'0')%2!=0){
              k=i;
              break;
            }
        }
        for(int i=0;i<=k;i++){
            s+=num[i];
        }
        return s;
    }
};