class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int hash[100001]={0};
        for(int i:nums){
            if(hash[i]>0){
                return i;
            }
            hash[i]++;
        }
        return 0;
    }
};