class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string>ans;
        int i=0;
        int n=nums.size();
        int prev=0;
        while(i<n){
         prev=i;
         while( i<n-1 && nums[i]+1==nums[i+1]){
            i++;
         }
         if(i==prev){
            ans.push_back(to_string(nums[i]));
         
         }else{
            ans.push_back(to_string(nums[prev])+"->" + to_string(nums[i]));
        }
        i++;
     }
        return ans;
    }
};