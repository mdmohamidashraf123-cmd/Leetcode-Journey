class Solution {
public:
   bool isp(string& s ,int st,int end){
     if(st>end){
        return true;
     }
    if(isalnum(s[st]) && isalnum(s[end])){
        if(tolower(s[st])!=tolower(s[end])){
             return false;
        }
        st++;
        end--;
    }else if(!isalnum(s[st])){
        st++;
    }else{
        end--;
    }
    return isp(s,st,end);
   }
   bool isPalindrome(string s){
    int st=0;
    int end=s.size()-1;
    return isp(s,st,end);
   }
};