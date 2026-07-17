class Solution {
public:
    bool rotateString(string s, string goal) {
        int k=0;
        if(s.length()!=goal.length()){
            return false;
        }
        int n=s.length();
        s+=s;
        if(s.find(goal)!=std::string::npos){
            return true;
        }else{
            return false;
        }
    }
};