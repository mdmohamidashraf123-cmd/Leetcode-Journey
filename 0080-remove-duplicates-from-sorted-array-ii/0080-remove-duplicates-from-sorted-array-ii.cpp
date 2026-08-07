class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>hash;
        for(int i=0;i<n;i++){
            hash[nums[i]]++;
        }
        int idx=0;
        int i=0;
        while(i<n){
            nums[idx]=nums[i];
            if (hash[nums[i]]>2){
             idx++;
             nums[idx]=nums[i];
             i+=hash[nums[i]];
            }else{
                i++;
            }
            idx++;
        }
        return idx;
    }
};