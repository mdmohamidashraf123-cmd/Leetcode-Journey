class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        int n=nums.size();
        int b=(1<<n);
        for(int i=0;i<b;i++){
            int j=0;
            vector<int>subs;
            int k=i;
            while(k>0){
                if((k & 1)==1){
                 subs.push_back(nums[j]);
                }
                j++;
                k=k>>1;
            } 
            ans.push_back(subs);
        }
        return ans;
    }
};