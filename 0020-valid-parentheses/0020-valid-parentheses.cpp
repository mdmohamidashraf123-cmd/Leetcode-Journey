class Solution {
public:
    bool isValid(string s) {
        int z=s.size();
        if(z==1){
            return false;
        }
        int a=0;
        int b=0;
        int c=0;
        int d=0;
        int e=0;
        int f=0;
        stack<int>p;
        for(int i=0;i<z;i++){
          if(p.size()!=0){
            if(s[i]==')'){
                d++;
                if(p.top()=='('){
                    p.pop();
                    continue;
                }else{
                    return false;
                }
            }else if(s[i]=='}'){
                e++;
                if(p.top()=='{'){
                    p.pop();
                    continue;
                }else{
                    return false;
                }
            }else if(s[i]==']'){
                f++;
                if(p.top()=='['){
                    p.pop();
                    continue;
                }else{
                    return false;
                }
            }
          }else{
             if(s[i]==')'|| s[i]=='}' || s[i]==']' ){
                return false;
             }
          }
          if(s[i]=='('){
            a++;
          }else if(s[i]=='{'){
            b++;
          }else if(s[i]=='['){
            c++;
          }
           p.push(s[i]);
        }
        if(a!=d || b!=e || c!=f){
            return false;
        }
        return true;
    }
};