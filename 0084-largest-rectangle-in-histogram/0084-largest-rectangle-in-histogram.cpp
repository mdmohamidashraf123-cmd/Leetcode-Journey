class Solution {
public:
    vector<int>pse(vector<int>& heights){
        int n=heights.size();
        vector<int>ans(n);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            ans[i]=st.empty()? -1 : st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int>nse(vector<int>& heights){
        int n=heights.size();
        vector<int>ans(n);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>heights[i]){
                st.pop();
            }
            ans[i]=st.empty()? n: st.top();
            st.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>ps=pse(heights);
        vector<int>ns=nse(heights);
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
           int p=ps[i];
           int n=ns[i];
           int area=heights[i]*(n-p-1);
           ans=max(ans,area);
        }
        return ans;
    }
};