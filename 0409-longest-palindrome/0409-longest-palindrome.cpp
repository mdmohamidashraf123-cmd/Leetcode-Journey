class Solution {
public:
    int longestPalindrome(string s) {
        int n=s.size();
        if(n==1){
            return 1;
        }
        int l=0;
        bool isodd=false;
        sort(s.begin(),s.end());
        int c=1;
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]){
               c++;
            }else{
                if(c%2!=0){
                   isodd=true;
                   l+=c-1;
                }else{
                    l+=c;
                }
                c=1;
            }
        }
        if(c%2!=0){
            isodd=true;
            l+=c-1;
        }else{
            l+=c;
        }
        if(isodd){
            l+=1;
        }
        return l;
    }
};