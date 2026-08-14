class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n);
        if(n==1){
            ans[0]=-1;
            return ans;
        }
        stack<int>b;
        stack<int>a;
        bool hash[10000]={true};
        ans[n-1]=-1;
        hash[n-1]=false;
        a.push(nums[n-1]);
        for(int i=n-2;i>=0;i--){
            while(!a.empty() && a.top()<=nums[i]){
                a.pop();
            }
            if(a.empty()){
                hash[i]=false;
            }else{
                hash[i]=true;
                ans[i]=a.top();
            }
            a.push(nums[i]);
            b.push(nums[i]);
        }
        int k=0;
        for(int i=n-1;i>=0;i--){
            if(!hash[i]){
                while(i!=0 &&!b.empty() && b.top()<=nums[i]){
                    b.pop();
                    k++;
                    if(k==i){
                        break;
                    }
                }
                if(b.empty() || k==i||i==0){
                    ans[i]=-1;
                }else{
                    ans[i]=b.top();
                }
            }
            
        }
        return ans;
    }
};