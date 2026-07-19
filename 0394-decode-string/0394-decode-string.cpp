class Solution {
public:
    string decodeString(string s) {
        stack<string>p;
        stack<int>n;
        int ans=0;
        string z="";
        string current="";
        for(char c:s){
            if(isdigit(c)){
               ans=ans*10+c-'0';
            }else if(c=='['){
                n.push(ans);
                p.push(current);
                current="";
                ans=0;
            }else if(c==']'){
                   int r=n.top();
                   n.pop();
                   string prev=p.top();
                   p.pop();
                   string temp="";
                  for(int i=0;i<r;i++){
                    temp+=current;
                  }
                  current=prev+temp;
            }else{
               current +=c;
            }
        }
        
        return current;
    }
};