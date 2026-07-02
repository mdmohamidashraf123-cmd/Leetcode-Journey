class Solution {
public:
    void subas(vector<int>& nums,vector<int>&subs,int n,vector<vector<int>>&ans){
        if(n==nums.size()){
            ans.push_back(subs);
            return;
        }
        //include
        subs.push_back(nums[n]);
        subas(nums,subs,n+1,ans);
        subs.pop_back();
        //exclude
        subas(nums,subs,n+1,ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>subs;
        vector<vector<int>>ans;
        int n=0;
        subas(nums,subs,n,ans);
        return ans;
    }
};