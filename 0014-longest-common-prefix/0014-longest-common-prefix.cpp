class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s="";
        int n=strs.size();
        for(int i=0; i<strs[0].size();i++){
            bool p=true;
            for(int j=1;j<n;j++){
                if(strs[0][i]!=strs[j][i]){
                    p=false;
                    break;
                }
            }
            if(p){
                s.push_back(strs[0][i]);
            }else{
                break;
            }
        }
        return s;
    }
};