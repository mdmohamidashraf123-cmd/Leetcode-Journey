class Solution {
public:
    void helper(vector<int>& candidates,int i,int target,vector<int>&v,vector<vector<int>>&ans){
        if(target==0){
         ans.push_back(v);
         return;
        }
        for(int j=i;j<candidates.size();j++){
         if(candidates[j]>target){
            break;
         }
         if(j>i && candidates[j]==candidates[j-1]){
            continue;
         }
         v.push_back(candidates[j]);
         //choice push
         helper(candidates,j+1,target-candidates[j],v,ans);
         //dont push
         //backtrack
         v.pop_back();
        
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>v;
        helper(candidates,0,target,v,ans);
        return ans;
    }
};