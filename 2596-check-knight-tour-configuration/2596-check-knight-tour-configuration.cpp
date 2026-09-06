class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        if(grid[0][0]!=0){
            return false;
        }
        int n=grid.size();
        int m=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                m=max(m,grid[i][j]);
            }
        }
        for(int i=0;i<n;i++){
          for(int j=0;j<n;j++){
            if(grid[i][j]==m) {
                continue;
            }
             int c=grid[i][j];
             bool x=false;
             if(i+2<n){
                if(j>0){
                    if(grid[i+2][j-1]==c+1){
                        x=true;
                        continue;
                    }
                }
                if(j<n-1){
                    if(grid[i+2][j+1]==c+1){
                        x=true;
                        continue;
                    }
                }
            }
            if(i-2>=0){
                if(j>0){
                    if(grid[i-2][j-1]==c+1){
                        x=true;
                        continue;
                    }
                }
                if(j<n-1){
                    if(grid[i-2][j+1]==c+1){
                        x=true;
                        continue;
                    }
                }
            }
            if(j-2>=0){
               if(i>0){
                    if(grid[i-1][j-2]==c+1){
                        x=true;
                        continue;
                    }
                }
                if(i<n-1){
                    if(grid[i+1][j-2]==c+1){
                        x=true;
                        continue;
                    }
                }
            }
            if(j+2<n){
               if(i>0){
                    if(grid[i-1][j+2]==c+1){
                        x=true;
                        continue;
                    }
                }
                if(i<n-1){
                    if(grid[i+1][j+2]==c+1){
                        x=true;
                        continue;
                    }
                }
            }
            if(x==false){
                return false;
            }
          }
        }
        return true;
    }
};