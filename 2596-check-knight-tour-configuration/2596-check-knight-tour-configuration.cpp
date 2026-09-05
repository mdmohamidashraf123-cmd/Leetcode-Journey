class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        if(grid[0][0]!=0){
            return false;
        }
        int n=grid.size();
        vector<pair<int,int>>x(n*n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                x[grid[i][j]]={i,j};
            }
        }
        for(int i=1;i<n*n;i++){
            int rdiff=abs(x[i].first-x[i-1].first);
            int cdiff = abs(x[i].second - x[i - 1].second);
            if(!(rdiff==2&& cdiff==1)&&!(rdiff=1 && cdiff==2)){
                return false;
            }
        }
        return true;
    }
};