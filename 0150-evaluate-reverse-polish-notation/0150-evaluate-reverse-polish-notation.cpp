class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        //postfix is also known as reverse polish notation
        stack<int>st;
        int n=tokens.size();
        for(int i=0;i<n;i++){
            if(tokens[i]=="+"||tokens[i]=="-"||tokens[i]=="/"||tokens[i]=="*"){
                int y=(st.top());
                st.pop();
                int x=(st.top());
                st.pop();
                int z=0;
                if(tokens[i]=="+"){
                   z=x+y;
                }else if(tokens[i]=="-"){
                    z=x-y;
                }else if(tokens[i]=="*"){
                    z=x*y;
                }else{
                    z=x/y;
                }
                st.push(z);
            }else{
                st.push(stoi(tokens[i]));
            }
        }
        int k=st.top();
        return k;
    }
};