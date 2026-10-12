class Solution {
public:
    //Better readabity and cleanliness and effeciency
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        queue<pair<int,int>>q;
        vector<vector<int>>dis(n,vector<int>(m,1e9));
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[i].size();j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                    dis[i][j]=0;
                }
            }
        }
        int drow[]={-1,0,0,1};
        int dcol[]={0,1,-1,0};
        while(!q.empty()){
            auto it=(q.front());
            q.pop();
            int row=it.first;
            int col=it.second;
            int dist=dis[row][col];
            for(int i=0;i<4;i++){
                int nrow=row+drow[i];
                int ncol=col+dcol[i];
                if(nrow<0|| ncol<0 || nrow>=mat.size()|| ncol>=mat[nrow].size()){
                    continue;
                }
                if(dis[nrow][ncol]!=1e9){
                    continue;
                }
                q.push({nrow,ncol});
                dis[nrow][ncol]=dist+1;
            }
        }
        return dis;
    }
};