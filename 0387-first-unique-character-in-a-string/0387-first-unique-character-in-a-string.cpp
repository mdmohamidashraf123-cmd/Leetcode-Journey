class Solution {
public:
    int firstUniqChar(string s) {
      queue<int>q;
      int n=s.size();
      int hash[127]={0};
      for(int i=0;i<n;i++){
        hash[s[i]]++;
        q.push(i);
        while(!q.empty() && hash[s[q.front()]]>1){
            q.pop();
        }
      }
      return q.empty()? -1 : q.front();
    }
};