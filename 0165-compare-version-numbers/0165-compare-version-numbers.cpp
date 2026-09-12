class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i=0;
        int j=0;
        long long a=0;
        long long b=0;
        while(i<version1.size() && j<version2.size()){
            while(i<version1.size() && version1[i]!='.'){
                a=a*10+version1[i]-'0';
                i++;
            }
            while(j<version2.size() && version2[j]!='.'){
                b=b*10+version2[j]-'0';
                j++;
            }
            if(a<b){
                return -1;
            }else if(a>b){
                return 1;
            }
            a=0;
            b=0;
            i++;
            j++;
        }
        
        if(i<version1.size()){
         while(i<version1.size()){
            
            a=version1[i]!='.'?a*10+version1[i]-'0':a;
            i++;
         }
         return a>0?1:0;
        }else if(j<version2.size()){
         while(j<version2.size()){
            b=version2[j]!='.'?b*10+version2[j]-'0':b;
            j++;
         }
         return b>0?-1:0;
        }
        return 0;
    }
};