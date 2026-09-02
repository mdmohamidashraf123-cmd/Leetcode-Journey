class Solution {
public:
    set<vector<int>>s;
    void helper(int i,vector<int>& candidates,vector<vector<int>>& ans,vector<int>&c,int target){
        if(target==0){
            if(s.find(c)==s.end()){
             ans.push_back(c);
             s.insert(c);
            }
            return;
        }
        if( i>=candidates.size()||target<0){
            return;
        }
        c.push_back(candidates[i]);
        helper(i,candidates,ans,c,target-candidates[i]);
        helper(i+1,candidates,ans,c,target-candidates[i]);
        c.pop_back();//backtrack
        helper(i+1,candidates,ans,c,target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>c;
        helper(0,candidates,ans,c,target);
        return ans;
    }
};