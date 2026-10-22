class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        //Using Binary Search-lower Bound Optimal Solution
        int n=nums.size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(ans.empty()||ans.back()<nums[i]){
                ans.push_back(nums[i]);
            }else{
                int c=lower_bound(ans.begin(),ans.end(),nums[i])-ans.begin();
                ans[c]=nums[i];
            }
        }
        return ans.size();
    }
};