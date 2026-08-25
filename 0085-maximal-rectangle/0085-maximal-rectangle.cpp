class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int>st;
        int ans=0;
        int ps;
        int ns;
        for(int i=0;i<n;i++){
           while(!st.empty() && heights[st.top()]>=heights[i]){
            int k=st.top();
            st.pop();
            ps=st.empty() ? -1: st.top();
            int width=i-ps-1;
            ans=max(ans,width*heights[k]);
           }
           st.push(i);
        }
        while(!st.empty()){
            ns=n;
            int k=st.top();
            st.pop();
            ps=st.empty()? -1:st.top();
            int width=ns-ps-1;
            ans=max(ans,width*heights[k]);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int r=matrix.size();
        int c=matrix[0].size();
        vector<vector<int>>prefixsum(r,vector<int>(c,0));
        for(int i=0;i<c;i++){
            int sum=0;
            for(int j=0;j<r;j++){
               if(matrix[j][i]=='0'){
                prefixsum[j][i]=0;
                sum=0;
               }else{
                sum+=matrix[j][i]-'0';
                prefixsum[j][i]=sum;
               }
            }
        }
        int ans=0;
        for(int i=0;i<r;i++){
           ans=max(ans ,largestRectangleArea(prefixsum[i]));
        }
        return ans;
    }
};