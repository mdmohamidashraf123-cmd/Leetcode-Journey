class Solution {
public:
    bool valid(vector<vector<int>>& grid,int i,int j){
        if(grid[i][j]==pow(grid.size(),2)-1){
           return true;
        }
        bool x=false;
        int n=grid.size();
        int c=grid[i][j];
        if(i+2<n && i+2>=0 && !x){
                if(j>0 && j<n){
                    if(grid[i+2][j-1]==c+1){
                        
                        x=valid(grid,i+2,j-1);
                    }
                }
                if(j<n-1&& j>=0 &&!x){
                    if(grid[i+2][j+1]==c+1){
                        x=valid(grid,i+2,j+1);
                    }
                }
        }
        if(i-2>=0 && i-2<n&& !x ){
            if(j>0 && j<n){
                if(grid[i-2][j-1]==c+1){
                    x= valid(grid,i-2,j-1);
                }
            }
            if(j<n-1&& !x&& j>=0 ){
                if(grid[i-2][j+1]==c+1){
                    x=valid(grid,i-2,j+1);
                }
            }
        }
        if(j-2>=0 && j-2<n&& !x){
            if(i>0 && i<n){
               if(grid[i-1][j-2]==c+1){
                    x=valid(grid,i-1,j-2);
                }
            }
            if(i<n-1 && i>=0 && !x ){
                if(grid[i+1][j-2]==c+1){
                    x=valid(grid,i+1,j-2);
                }
            }
        }
        if(j+2<n && j+2>=0 && !x){
            if(i>0 && i<n ){
                if(grid[i-1][j+2]==c+1){
                    x=valid(grid,i-1,j+2);
                }
            }
            if(i<n-1&& i>=0&&!x ){
                if(grid[i+1][j+2]==c+1){
                    x=valid(grid,i+1,j+2);
                }
            }
        }
        return x;
    }
    bool checkValidGrid(vector<vector<int>>& grid) {
        if(grid[0][0]!=0){
            return false;
        }
        int n=grid.size();
        return valid(grid,0,0);
        
    }
};