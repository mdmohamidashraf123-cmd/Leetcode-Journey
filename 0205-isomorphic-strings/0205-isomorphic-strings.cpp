class Solution {
public:
    bool isIsomorphic(string s, string t) {
       unordered_map<char,char>r;
       unordered_map<char,char>l;
        for(int i=0;i<s.size();i++){
         char a=s[i];
         char b=t[i];
         if( r.count(a) && r[s[i]]!=t[i]){
            return false;
         }
         if(l.count(b) && l[t[i]]!=s[i]){
            return false;
         }
          r[s[i]]=t[i];
          l[t[i]]=s[i];
        }
        return true;
    }
};