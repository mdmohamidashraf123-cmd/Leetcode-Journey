class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>>transpose(n);
        for(int j=0;j<n;j++){
            for(int i=0;i<m;i++){
                transpose[j].push_back(matrix[i][j]);
            }
        }
        return transpose;
    }
};