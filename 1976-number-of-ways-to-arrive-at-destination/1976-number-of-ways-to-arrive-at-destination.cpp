class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        //using Djkstra's Algorithm
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0;i<roads.size();i++){
            adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }
        vector<long long>dis(n,1e18);
        vector<long long>ways(n,0);
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
        dis[0]=0;
        ways[0]=1;
        pq.push({0,0});
        int mod=int(1e9+7);
        while(!pq.empty()){
            long long dist=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto it:adj[node]){
                int adjnode=it.first;
                long long ew=it.second;
                if(dist+ew<dis[adjnode]){
                    dis[adjnode]=dist+ew;
                    pq.push({dist+ew,adjnode});
                    ways[adjnode]=ways[node];
                }else if(dist+ew==dis[adjnode]){
                    ways[adjnode] = (ways[adjnode] + ways[node]) % mod;
                }
            }
        }
        return ways[n-1]%mod;
    }
};