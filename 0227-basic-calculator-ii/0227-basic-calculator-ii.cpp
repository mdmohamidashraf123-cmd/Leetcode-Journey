class Solution {
public:
    int p(char i){
        if(i=='/'|| i=='*'){
            return 2;
        }else if(i=='+'|| i=='-'){
            return 1;
        }else {
            return 0;
        }
    }
    int calculate(string s) {
        //evaluation of infix expression
        int n=s.size();
        stack<string>st;
        stack<char>op;
        string k;
        for(int i=0;i<n;i++){
            if(isalnum(s[i])){
              k.push_back(s[i]);
            }else if(s[i]!=' '){
                if(!k.empty()){
                    st.push(k);
                    k="";
                }
                while(!op.empty() && p(s[i])<=p(op.top())){
                    int z;
                    int x=stoi(st.top());
                    st.pop();
                    int y=stoi(st.top());
                    st.pop();
                    if(op.top()=='+'){
                        z= y+x;
                    }else if(op.top()=='-'){
                        z= y-x;
                    }else if(op.top()=='*'){
                        z= y*x;
                    }else if(op.top()=='/'){
                        z= y/x;
                    }
                    op.pop();
                    st.push(to_string(z));
                }
                op.push(s[i]);
            }
        }
        if(!k.empty()){
            st.push(k);
            k="";
        }
        while(!op.empty() && !st.empty()){
            int z;
            int y=stoi(st.top());
            st.pop();
            int x;
            if(!st.empty()){
             x=stoi(st.top());
            st.pop();
            }
            if(op.top()=='+'){
                z= x+y;
            }else if(op.top()=='-'){
                z= x-y;
            }else if(op.top()=='*'){
                z= x*y;
            }else if(op.top()=='/'){
                z= x/y;
            }
            op.pop();
            st.push(to_string(z));
        }
        int ans=stoi(st.top());
        return ans;
        
    }
};