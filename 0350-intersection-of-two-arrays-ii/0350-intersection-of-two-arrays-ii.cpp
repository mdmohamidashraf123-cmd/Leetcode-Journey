class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        vector<int>ans;
        int hash[1001]={0};
        for(int i:nums1){
            hash[i]++;
        }
        int i=0;
        int c=0;
        while(i<nums2.size()){
            if(hash[nums2[i]]>0){
                c++;
                int a=i+1;
                while(a<nums2.size() && nums2[a]==nums2[i]){
                 c++;
                 a++;
                }
               c=min(hash[nums2[i]],c);
               for(int k=0;k<c;k++){
                ans.push_back(nums2[i]);
               }
               i=a;
               c=0;
            }else{
                i++;
            }
        }
        return ans;
    }
};