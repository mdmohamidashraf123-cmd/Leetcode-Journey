class Solution {
public:
    string simplifyPath(string path) {
        stack<string>st;
        string ans="";
        int i=0;
        string k;
        while(i<path.size()){
            if(path[i]=='/'){
                i++;
            }else{
                if(path[i]=='.'){
                    k="";
                    int c=0;
                    int j=i;
                    while(i<path.size()&& path[i]!='/'){
                        k.push_back(path[i]);
                        if(path[i]=='.'){
                         c++;
                        }
                        i++;
                    }
                    if(c==i-j){
                        if(c==2 && !st.empty()){
                           st.pop();
                        }else if(c>2){
                            st.push(k);
                        }
                    }else{
                        st.push(k);
                    }
                }else{
                    //alphabet
                    k="";
                    while(i<path.size()&& path[i]!='/'){
                        k.push_back(path[i]);
                        i++;
                    }
                    st.push(k);
                }
                continue;
            }
        }
        if(st.empty()){
            ans="/";
        }
        while(!st.empty()){
            ans="/"+st.top()+ans;
            st.pop();
        }
        return ans;
    }
};