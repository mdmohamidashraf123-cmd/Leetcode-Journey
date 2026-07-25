class Solution {
public:
    string  q(int& i,string &s){
        string current="";
        while(i<s.size() && s[i]!=']'){
            if(!isdigit(s[i])){
                current+=s[i];
                i++;
            }else{
                int ans=0;
                while(i<s.size() && isdigit(s[i])){
                    ans=ans*10+s[i]-'0';
                    i++;
                }
                i++;
               string nested=q(i,s);
               i++;
                while(ans>0){
                    current+=nested;
                    ans--;
                }
            }
        }
        return current;
        
    }
    string decodeString(string s) {
        int i=0;
        return q(i,s);
    }
};