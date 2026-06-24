class Solution {
public:
    string reverseWords(string s) {
        string rev="";
        vector<string>w;
        string a="";
        int words=0;
        int n=s.size()-1;
        int k=0;
        int j;
        for(int i=0;i<=n;i++){
          if(isalnum(s[i])){
           k++;
           j=0;
           a+=s[i];
           
          }else{
            if(k>0 &&j==0){
             words++;
            }
            if (!a.empty()){
                w.push_back(a);
            }
            j++;
            a="";
          }
        }
        if (!a.empty()) {
          w.push_back(a);
        }
        //now you have w vector which consists of all the words
        for (int i=w.size()-1;i>=0;i--){
            rev+=(w[i]);
           if (i != 0){
            rev+=" ";
           }
        }
        return rev;
    }
};