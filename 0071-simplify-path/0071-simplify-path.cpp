class Solution {
public:
    string simplifyPath(string path) {
        stack<string>st;
        int a=0;
        int i=0;
        while(i<path.size()){
            if(path[i]=='/'){
                if(!st.empty() && st.top()=="/"){
                    st.pop();
                }
                st.push("/");
                while(i<path.size()&& path[i]=='/'){
                    i++;
                }
                continue;
            }else if(path[i]=='.'){
                string k;
                while(i<path.size() && path[i]!='/'){
                    k.push_back(path[i]);
                    if(path[i]=='.'){
                     a++;
                    }
                    i++;
                }
                if(a==2 && path[i-1]=='.'){
                  int g=0;
                  while(!st.empty() && g<3 ){
                    if(!st.empty() && st.top()=="/" && st.size()==1){
                        break;
                    }
                    st.pop();
                    g++;
                    
                   }
                }else if(a>2){
                    st.push(k);
                }else{
                    if(path[i-1]!='.'){
                        st.push(k);
                    }
                }
                a=0;
                continue; 
            }else{
                string k;
                while(i<path.size() && path[i]!='/'){
                    k.push_back(path[i]);
                    i++;
                }
                st.push(k);
                continue;
            }
            i++;
        }
        if(st.top()=="/" && st.size()>1){
            st.pop();
        }
        string ans="";
        while(!st.empty()){
           ans=st.top()+ans;
           st.pop();
        }
        return ans;
    }
};