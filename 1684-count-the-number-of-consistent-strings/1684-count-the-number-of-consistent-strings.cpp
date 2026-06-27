class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int c=0;
        for(string i:words){
            for(int a=0;a<i.size();a++){
                if(allowed.find(i[a])==string::npos){
                    break;
                }
                if(a==i.size()-1){
                    c++;
                }
            }
        }
        return c;
    }
};