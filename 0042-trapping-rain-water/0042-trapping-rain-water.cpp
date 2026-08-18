class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        stack<int>st;
        int s=0;
        int ans=0;
        for(int i=0;i<n;i++){
           while(!st.empty() && height[s]<height[i]){
              ans+=(height[s]-st.top());
              st.pop();
           }
           st.push(height[i]);
           if(st.size()==1){
            s=i;
           }
        }
        int max=st.top();
        while(!st.empty()){
            if(st.top()>max){
                max=st.top();
            }else{
             ans+=max-st.top();
            }
            st.pop();
        }
        return ans;
    }
};