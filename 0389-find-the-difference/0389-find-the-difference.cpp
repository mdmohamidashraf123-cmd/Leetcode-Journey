class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int>m;
        for(char i:s){
            m[i]++;
        }
        for(char i:t){
            if(m[i]==0){
                return i;
            }
            m[i]--;
        }
        return std::string::npos;

    }
};