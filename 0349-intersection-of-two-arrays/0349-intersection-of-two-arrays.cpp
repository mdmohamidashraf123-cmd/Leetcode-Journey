class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        //using hashing
        int f[1000]={0};
        for(int i:nums1){
            if(f[i]==0){
                f[i]++;
            }
        }
        int a[1000]={0};
        for(int i:nums2){
            a[i]++;
            if(f[i]>0 && a[i]==1 ){
               ans.push_back(i);
            }
        }
        return ans;
    }
};