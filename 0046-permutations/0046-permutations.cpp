class Solution {
public:
    void p(vector<int>& nums,int idx,vector<vector<int>>&k){
        if(idx==nums.size()){
            k.push_back({nums});
            return;
        }
       for(int i=idx;i<nums.size();i++){
          swap(nums[idx],nums[i]);
          p(nums,idx+1,k);
          swap(nums[idx],nums[i]);
       }
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>s;
        vector<vector<int>>k;
        p(nums,0,k);
        return k;
    }
};