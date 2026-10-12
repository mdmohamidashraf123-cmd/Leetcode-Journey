class Solution {
public:
    bool ischeck(int start,vector<int>&vis,vector<vector<int>>& graph){
        queue<pair<int,int>>q;
       //0 red 1 green
       q.push({start,0});
       vis[start]=0;
       while(!q.empty()){
          auto pair=q.front();
          q.pop();
          int node=pair.first;
          int col=pair.second;
          for(int j:graph[node]){
            if(vis[j]==1e9){
                if(col==0){
                q.push({j,1});
                vis[j]=1;
                }else{
                 q.push({j,0});
                 vis[j]=0;
                }
            }else{
               if(col==vis[j]){
                 return false;
               }
            }
          }
       }
       return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>vis(n,1e9);
       for(int i=0;i<n;i++){
            if(vis[i]==1e9){
                if(!ischeck(i,vis,graph)){
                  return false;
                }
            }
       }
        return true;
    }
};