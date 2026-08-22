class Solution {
public:
    vector<int>psee(vector<int>& nums){
        int n=nums.size();
        stack<int>st;
        vector<int>psee(n,-1);
        for(int i=0;i<n;i++){
           while(!st.empty() && nums[st.top()]>nums[i]){
            st.pop();
           }
           psee[i]=st.empty()? -1: st.top();
           st.push(i);
        }
        return psee;
    }
    vector<int>nse(vector<int>&arr){
        int n=arr.size();
        stack<int>st;
        vector<int>nse(n,n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            nse[i]=st.empty()? n: st.top();
            st.push(i);
        }
        return nse;
    }
    vector<int>pgee(vector<int>& nums){
        int n=nums.size();
        stack<int>st;
        vector<int>pgee(n,-1);
        for(int i=0;i<n;i++){
           while(!st.empty() && nums[st.top()]<nums[i]){
            st.pop();
           }
           pgee[i]=st.empty()? -1: st.top();
           st.push(i);
        }
        return pgee;
    }
    vector<int>nge(vector<int>&arr){
        int n=arr.size();
        stack<int>st;
        vector<int>nge(n,n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]<=arr[i]){
                st.pop();
            }
            nge[i]=st.empty()? n: st.top();
            st.push(i);
        }
        return nge;
    }
    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
        long long ans=0;
        vector<int>pse=psee(nums);
        vector<int>ns=nse(nums);
        vector<int>pge=pgee(nums);
        vector<int>ng=nge(nums);
        for(int i=0;i<n;i++){
            int p=pse[i];
            int n=ns[i];
            long long m=(i-p)*(n-i);
            ans-=1LL*(nums[i]*m);
            int x=pge[i];
            int y=ng[i];
            long long max=(i-x)*(y-i);
            ans+=1ll*(nums[i]*max);
        }
        return ans;
    }
};