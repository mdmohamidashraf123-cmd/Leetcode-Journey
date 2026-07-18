class Solution {
public:
    bool isValid(string s) {
        int z=s.size();
        if(z==1){
            return false;
        }
        stack<char>p;
        for(int i=0;i<z;i++){
          if(s[i]=='['|| s[i]=='{'|| s[i]=='('){
            p.push(s[i]);
          }else{
            if(p.empty()){
                return false;
            }else{
                if(s[i]==']'&& p.top()!='['){
                    return false;
                }else if(s[i]=='}' && p.top()!='{'){
                    return false;
                }else if(s[i]==')' &&p.top()!='(' ){
                    return false;
                }
                p.pop();
            }
          }
        }
        if(!p.empty()){
            return false;
        }
        return true;
    }
};