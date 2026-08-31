class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
       queue<pair<int,int>>q;
       for(int i=0;i<tickets.size();i++){
        q.push({i,tickets[i]});
       }
       int i=0;
       int t=0;
       while(!q.empty()){
        int c=q.front().second;
        int x=q.front().first;
        q.pop();
        c--;
        t++;
        if(c==0 &&x==k ){
           return t;
        }
        if(c!=0){
           q.push({x,c});
        }
        i++;
       }
       return t;
    }
};