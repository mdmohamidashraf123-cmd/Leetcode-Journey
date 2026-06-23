class Solution {
public:
   void setelemntszero(vector<vector<int>>& matrix,int i,int j){
    int c=matrix[0].size();
    int r=matrix.size();
    for(int k=0;k<r;k++){
        matrix[k][j]=0;
    }
    for(int p=0;p<c;p++){
        matrix[i][p]=0;
    }
    return;
   }
    void setZeroes(vector<vector<int>>& matrix) {
        int r=matrix.size();
        int c=matrix[0].size();
        vector<vector<int>>m(r*c);
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                m[i].push_back(matrix[i][j]);
            }
        }
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(m[i][j]==0){
                    setelemntszero(matrix,i,j);
                }
            }
        }
    }
};