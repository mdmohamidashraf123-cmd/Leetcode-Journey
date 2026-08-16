class Solution {
public:
    string removeKdigits(string num, int k) {
        if(num.size()==k){
            return "0";
        }
        stack<int>st;
        int n=num.size();
        int x=n-k;
        for(int i=0;i<num.size();i++){
            while(!st.empty() && st.top()>(num[i]-'0') && (n-i)>x-st.size()){
                st.pop();
            }
            if(st.size()<x){
             st.push(num[i]-'0');
            }
        }
        if(st.empty()){
            return "0";
        }
        string ans;
        while(!st.empty()){
            ans+=to_string(st.top());
            st.pop();
        }
        if(ans.size()==1){
            return ans;
        }
        int a=ans.size();
        int i=a-1;
        //deal with leading zeroes
        while(i>=0 && ans[i]=='0'){
            i--;
        }
        if(i==-1){
           return "0";
        }
        ans.resize(i+1);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};