class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
       int n=gas.size();
       int tg=0;
       int tc=0;
       for(int i=0;i<n;i++){
        
       }
       
       int st=0;
       int cg=0;
       for(int i=0;i<n;i++){
        tg+=gas[i];
        tc+=cost[i];
        cg+=gas[i]-cost[i];
        if(cg<0){
            cg=0;
            st=i+1;
        }
       }
       return tg<tc ? -1: st;
    }
};