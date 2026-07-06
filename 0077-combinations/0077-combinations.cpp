class Solution {
public:
    void combination(vector<int>&s,vector<vector<int>>&a,int n,int k,int i){
        if(s.size()>=k){
            a.push_back(s);
            return;
        }
        for(int j=i;j<=n;j++){
         s.push_back(j);
         combination(s,a,n,k,j+1);
         s.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
       vector<vector<int>>c;
       vector<int>s;
       combination(s,c,n,k,1);
       return c;
    }
};