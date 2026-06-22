class Solution {
public:
    pair<int,int> minr(vector<vector<int>>& mat,int i,int c){
        int minr=mat[i][0];
        pair<int,int>p;
        int f=0;
        for(int j=0;j<c;j++){
            if (minr>mat[i][j]){
                minr=mat[i][j];
                f=j;
            }
        }
        p.first=minr;
        p.second=f;
        return p ;
    }
    int maxc (vector<vector<int>>& mat,int x,int r){
       int maxc=mat[0][x];
        for(int i=0;i<r;i++){
           if(maxc<mat[i][x]){
             maxc=mat[i][x];
           }
        }
        return maxc;
    }
    vector<int> luckyNumbers(vector<vector<int>>& mat) {
        vector<int>ln;
        int r=mat.size();
        int c=mat[0].size();
        for(int i=0;i<r;i++){
            pair<int,int>p=minr(mat,i,c);
            int j=p.first;
            int k=maxc(mat,p.second,r);
            if(j==k){
                ln.push_back(k);
            }
        }
        return ln;
    }
};