class Solution {
public:
    void rev(vector<char>& s,int st , int end){
        if(st>=end){
            return;
        }
        if(st >=0 && st<s.size() && end>=0 && st<s.size()){
        swap(s[st],s[end]);
        }
        rev(s,st+1,end-1);
    }
    void reverseString(vector<char>& s) {
        int st=0;
        int end=s.size()-1;
        rev(s,st,end);
    }
};