class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>>m;
        for(vector i:matrix){
            m.push_back(i);
        }
        
        int c=n-1;
        for(int i=0;i<n;i++){
            int r=0;
            for(int j=0;j<n;j++){
                if(r<n){
                matrix[r][c]=m[i][j];
                r++;
                }
            }
            c--;
        }
    }
};