class Solution {
public:
    string removeKdigits(string num, int k) {
        if(num.size()==k){
            return "0";
        }
        int n=num.size();
        int x=n-k;
        string ans;
        for(int i=0;i<num.size();i++){
            while(!ans.empty() && ans[ans.size()-1]>(num[i]) && k>0){
                ans.pop_back();
                k--;
            }
            if(ans.size()!=0||(num[i]!='0')){
             ans.push_back(num[i]);
            }
        }
        while (!ans.empty() && k > 0) {
            ans.pop_back();
            k--;
        }
        if(ans.empty()){
            return "0";
        }
        return ans;
    }
};