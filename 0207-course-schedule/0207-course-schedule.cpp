class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prereq) {
        int n=prereq.size();
        vector<vector<int>>adj(numCourses);
        vector<int>ined(numCourses,0);
        int v=0;
        for(int i=0;i<n;i++){
            adj[prereq[i][0]].push_back(prereq[i][1]);
            ined[prereq[i][1]]++;
        }
        //bfs
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(ined[i]==0){
                q.push(i);
            }
        }
        vector<int>ans;
        while(!q.empty()){
            int d=q.front();
            v++;
            ans.push_back(d);
            q.pop();
            for(int j:adj[d]){
                ined[j]--;
                if(ined[j]==0){
                    q.push(j);
                }
            }
        }
        
        return v==numCourses;
    }
};