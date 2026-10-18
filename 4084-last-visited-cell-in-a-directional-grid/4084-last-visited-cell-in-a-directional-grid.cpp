class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        vector<int>ans(2);
        int n=grid.size();
        int m=grid[0].size();
        int i=0,j=0;
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        while(i<n){
            while(j<m){
                vis[i][j]=true;
                if(grid[i][j]=='R'){
                    j++;
                    if(j>=m||vis[i][j]){
                        ans[0]=i;
                        ans[1]=j-1;
                        i=n+1;
                        break;
                    }
                }else if(grid[i][j]=='L'){
                    j--;
                    if(j<0||vis[i][j]){
                        ans[0]=i;
                        ans[1]=j+1;
                        i=n+1;
                        break;
                    }
                }else if(grid[i][j]=='U'){
                    i--;
                    if(i<0 || vis[i][j]){
                        ans[0]=i+1;
                        ans[1]=j;
                        i=n+1;
                        break;
                    }
                }else{
                    i++;
                    if(i>=n || vis[i][j]){
                        ans[0]=i-1;
                        ans[1]=j;
                        i=n+1;   
                        break;
                    }
                } 
            }
            //
        }
        
         return ans;
    }
};