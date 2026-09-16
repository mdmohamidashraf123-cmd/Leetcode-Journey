class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //Optimized approach
        //T.C (N)
        //Concept of buckets
        int n=nums.size();
        int ones=0;
        int twos=0;
        for(int i=0;i<n;i++){
            ones=(ones^nums[i])& ~(twos);
            twos=(twos^nums[i]) & ~(ones);
        }
        return ones;
    }
};