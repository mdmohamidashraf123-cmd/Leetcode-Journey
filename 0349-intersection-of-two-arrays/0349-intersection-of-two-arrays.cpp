class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        vector<int>ans;
        int i=0;
        while(i<nums2.size()){
            int st=0;
            int end=nums1.size()-1;
            while(st<=end){
             int mid=st+(end-st)/2;
             if(nums1[mid]>nums2[i]){
                end=mid-1;
             }else if(nums1[mid]==nums2[i]){
                ans.push_back(nums1[mid]);
                break;
             }else {
                st=mid+1;
             }
            }
            int a=i+1;
            while(a<nums2.size()&& nums2[a]==nums2[i]){
               a++;
            }
            i=a;
        }
        return ans;
    }
};