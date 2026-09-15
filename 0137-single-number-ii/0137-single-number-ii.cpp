class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //not optimized
        int n=nums.size();
        int ans=0;
        for(int i=0;i<32;i++){
            int c=0;
            for(int j=0;j<n;j++){
                if(nums[j] & (1<<i)){
                 c++;
                }
            }
            if(c%3!=0){
              ans=ans|(1<<i);
            }
        }
        return ans;
    }
};