class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int rows=grid.size();
        int col=grid[0].size();
        vector<int>ans;
        unordered_map<int,int>m;
        for(int i=0;i<rows;i++){
            for(int j=0;j<col;j++){
                m[grid[i][j]]++;
                if(m[grid[i][j]]==2){
                    ans.push_back(grid[i][j]);
                }
            }
        }
        for(int i=1;i<=rows*rows;i++){
            if(m[i]==0){
                ans.push_back(i);
            }
        }
        return ans;
    }
};