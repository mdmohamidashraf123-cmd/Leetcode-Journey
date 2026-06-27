class Solution {
public:
    string removeOuterParentheses(string s) {
        int n=s.length();
        if(n==1 || n==2){
            return "";
        }
        string s2;
        int c1=0;
        int c2=0;
        //check it in vs code some changes are required
        for(int i=0;i<n;i++){
          if(s[i]=='('){
            c1++;
            if(c1!=1){
                s2.push_back(s[i]);
            }
          }else{
            c2++;
            if(c2==c1){
                c1=0;
                c2=0;
            }else{
                s2.push_back(s[i]);
            }
          }
        }
        return s2;
    }
};