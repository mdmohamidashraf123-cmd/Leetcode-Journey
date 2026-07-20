class Solution {
public:
    char game(int k,string &s,string& a){
        if(a.size()>=k){
            return a[k-1];
        }
        s+=a;
        for(int i=0;i<a.size();i++){
            a[i]++;
        }
        s+=a;
        a=s;
        s="";
        return game(k,s,a);
    }
    char kthCharacter(int k) {
        if(k==1){
            return 'a';
        }
        string a="a";
        string s="";
        return game(k,s,a);
    }
};