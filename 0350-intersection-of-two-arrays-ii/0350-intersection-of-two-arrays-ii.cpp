class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        int hash[1001]={0};
        for(int i:nums1){
            hash[i]++;
        }
        for(int i:nums2){
            if(hash[i]>0){
             ans.push_back(i);
             hash[i]--;
            }
        }
        return ans;
    }
};