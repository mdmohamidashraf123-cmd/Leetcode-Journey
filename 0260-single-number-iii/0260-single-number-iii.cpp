class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        //using concept of buckets
        int n=nums.size();
        long long x=0;//long long used here because if (x==2^-31 then x-1 will overflow)
        for(int i:nums){
            x^=i;
        }
        int b1=0;
        int b2=0;
        int c=(x&x-1)^x;
        for(int i:nums){
            if((i & c)==0){
                b1=b1^i;
            }else{
                b2=b2^i;
            }
        }
        vector<int>ans;
        ans.push_back(b1);
        ans.push_back(b2);  
        return ans;
    }
};