class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int>m;
        int n=nums.size();
        for(int i:nums){
            m[i]++;
        }
        vector<int>ans;
        unordered_map<int,bool>a;
        for(int i:nums){
            a[i]=true;
        }
        for(int i=0;i<n;i++){
            if(m[nums[i]]>n/3){
                if(a[nums[i]]){
                ans.push_back(nums[i]);
                a[nums[i]]=false;
                }
            }
        }
        return ans;
    }
};