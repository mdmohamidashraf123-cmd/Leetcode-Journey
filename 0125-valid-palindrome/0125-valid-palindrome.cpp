class Solution {
public:
   bool isPalindrome(string s){
     int st=0;
     int end=s.size()-1;
     while(st<=end){
       if(isalnum(s[st]) && isalnum(s[end])){
         if(tolower(s[st])!=tolower(s[end])){
             return false;
         }
       }else if(!isalnum(s[st])){
         st++;
         continue;
        }else{
          end--;
          continue;
        }
        st++;
        end--;
    }
    return true;
  }
};