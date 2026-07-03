class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int st=0;
        int end=n-1;
        if (end==0){
            return nums[0];
        }

        while(st<=end){
           int mid=st+(end-st)/2;
           if((mid==0|| nums[mid]!=nums[mid-1] )&& (mid==n-1|| nums[mid]!=nums[mid+1])){
             return nums[mid];
           }else if(mid!=0 && nums[mid-1]==nums[mid]){
            if(mid%2==0){
             end=mid-2;
            }else{
                st=mid+1;
            }
           }else{
            if(mid%2==0){
             st=mid+2;
            }else{
                end=mid-1;
            }
           }
        }
        return -1;
    }
};