class Solution {
public:
    // vector<int>pse(vector<int>& heights){
    //     int n=heights.size();
    //     vector<int>ans(n);
    //     stack<int>st;
    //     for(int i=0;i<n;i++){
    //         while(!st.empty() && heights[st.top()]>=heights[i]){
    //             st.pop();
    //         }
    //         ans[i]=st.empty()? -1 : st.top();
    //         st.push(i);
    //     }
    //     return ans;
    // }
    // vector<int>nse(vector<int>& heights){
    //     int n=heights.size();
    //     vector<int>ans(n);
    //     stack<int>st;
    //     for(int i=n-1;i>=0;i--){
    //         while(!st.empty() && heights[st.top()]>heights[i]){
    //             st.pop();
    //         }
    //         ans[i]=st.empty()? n: st.top();
    //         st.push(i);
    //     }
    //     return ans;
    // }
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>ps(n);
        stack<int>st;
        vector<int>ns(n,n);
        int ans=0;
        for(int i=0;i<n;i++){
           while(!st.empty() && heights[st.top()]>=heights[i]){
            ns[st.top()]=i;
            int width=ns[st.top()]-ps[st.top()]-1;
            ans=max(ans,width*heights[st.top()]);
            st.pop();
           }
           ps[i]=st.empty()? -1 : st.top();
           st.push(i);
        }
        while(!st.empty()){
            ns[st.top()]=n;
            int width=ns[st.top()]-ps[st.top()]-1;
            ans=max(ans,width*heights[st.top()]);
            st.pop();
        }
        return ans;
    }
};