class Solution {
public:
    int romanToInt(string s) {
        int f=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='I'){
                if(s[i+1]=='V'){
                    f+=4;
                    i++;
                }else if(s[i+1]=='X'){
                    f+=9;
                    i++;
                }else{
                    f+=1;
                }
            }else if(s[i]=='X'){
                if(s[i+1]=='L'){
                    f+=40;
                    i++;
                }else if(s[i+1]=='C'){
                    f+=90;
                    i++;
                }else{
                    f+=10;
                }
            }else if(s[i]=='C'){
                if(s[i+1]=='D'){
                    f+=400;
                    i++;
                }else if(s[i+1]=='M'){
                     f+=900;
                     i++;
                }else{
                    f+=100;
                }
            }else if(s[i]=='V'){
                f+=5;
            }else if(s[i]=='L'){
                f+=50;
            }else if(s[i]=='D'){
                f+=500;
            }else{
                f+=1000;
            }
        }
        return f;
    }
};