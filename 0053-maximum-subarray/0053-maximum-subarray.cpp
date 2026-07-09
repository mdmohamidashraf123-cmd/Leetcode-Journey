class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ma=INT_MIN;
        int n=nums.size();
        int cursum=0;
        for(int i=0;i<n;i++){
            cursum+=nums[i];
            ma=max(cursum,ma);
            if(cursum<0){
               cursum=0;
            }
        }
        return ma;
    }
};