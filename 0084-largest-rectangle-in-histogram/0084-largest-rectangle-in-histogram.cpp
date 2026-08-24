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
};