class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>st;
        int n=nums1.size();
        int m=nums2.size();
        vector<int>ans(n);
        unordered_map<int,int>hash;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(nums2[j]==nums1[i]){
                    hash[j]=i;
                    break;
                }
            }
        }
        for(int i=m-1;i>=0;i--){
            while(!st.empty() && st.top()<=nums2[i]){
                st.pop();
            }
            if(hash.count(i)){
             if(st.empty()){
               ans[hash[i]]=-1;
             }else{
               ans[hash[i]]=st.top();
             }
            }
            st.push(nums2[i]);
        }
        return ans;
    }
};