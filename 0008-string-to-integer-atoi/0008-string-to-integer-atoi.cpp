class Solution {
public:
    int myAtoi(string s) {
        int c=0,k=10;
        int a=0,b=0,e=0;
        bool p=true;
        long long ans=0;
        for(int i=0;i<s.size();i++){
          if ((tolower(s[i])>='a' && tolower(s[i])<='z') || (s[i]==' ' && (a>0 ||c>0||e>0||b>0))){
            break;
          }else if(s[i]>='1' && s[i]<='9'){
            c++;
            ans=ans*10+(s[i]-'0');
          }else if(s[i]=='0'){
            a++;
            if(c>0){
              ans=ans*10+(s[i]-'0');
            }
          }else if(s[i]=='-'){
            e++;
            if(e>1){
                break;
            }
            if(a>0|| c>0|| b>0){
            break;
            }else{
                p=false;
            }
          }else if(s[i]=='.'){
            break;
          }else if(s[i]=='+'){
            b++;
            if(b>1){
                break;
            }
            if(c>0||a>0|| e>0){
             break;
            }
          }
          if(ans>INT_MAX && p){
            return INT_MAX;
          }
          if(!p && ans>(long long)INT_MAX+1){
            return INT_MIN;
          }
       }
       if(!p){
        ans*=-1;
       }
       return ans;
    }
};