class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
       sort(intervals.begin(),intervals.end());
       int n=intervals.size();
       if(n==1){
        return intervals;
       }
       int idx=0;
       unordered_map<int,bool>a;
       a[0]=true;
       while(idx<n){
        if(a[idx]){
        for(int i=idx+1;i<n;i++){
          if(intervals[idx][1]>=intervals[i][0]){
            intervals[idx][1]=max(intervals[i][1],intervals[idx][1]);
            a[i]=false;
          }else{
            a[i]=true;
            break;
          }
        }
        }
        idx++;
       }
       idx=0;
       for(int i=0;i<n;i++){
           if(a[i]){
            intervals[idx]=intervals[i];
            idx++;
           }
       }
       intervals.resize(idx);
       return intervals;
    }
};