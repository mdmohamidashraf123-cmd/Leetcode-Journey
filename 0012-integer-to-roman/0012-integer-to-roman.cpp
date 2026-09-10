class Solution {
public:
    string intToRoman(int num) {
        string a=to_string(num);
        // char hash[9]={'I','I','I','V','V','V','L','C','D','M'};
        string ans;
        int n=a.size();
        for(char i:a){
           if(i=='1'){
              if(n==1){
                ans+="I";
              }else if(n==2){
                ans+="X";
              }else if(n==3){
                ans+="C";
              }else{
                ans+="M";
              }
              n--;
           }else if(i=='2'){
              if(n==1){
                ans+="II";
              }else if(n==2){
                ans+="XX";
              }else if(n==3){
                ans+="CC";
              }else{
                ans+="MM";
              }
              n--;
           }else if(i=='3'){
              if(n==1){
                ans+="III";
              }else if(n==2){
                ans+="XXX";
              }else if(n==3){
                ans+="CCC";
              }else{
                ans+="MMM";
              }
              n--;
           }else if(i=='4'){
            if(n==1){
                ans+="IV";
            }else if(n==2){
                ans+="XL";
            }else if(n==3){
                ans+="CD";
            }
            n--;
           }else if(i=='5'){
            if(n==1){
                ans+="V";
            }else if(n==2){
                ans+="L";
            }else if(n==3){
                ans+="D";
            }
            n--;
           }else if(i=='6'){
             if(n==1){
                ans+="VI";
            }else if(n==2){
                ans+="LX";
            }else if(n==3){
                ans+="DC";
            }
            n--;
           }else if(i=='7'){
            if(n==1){
                ans+="VII";
            }else if(n==2){
                ans+="LXX";
            }else if(n==3){
                ans+="DCC";
            }
            n--;
           }else if(i=='8'){
            if(n==1){
                ans+="VIII";
            }else if(n==2){
                ans+="LXXX";
            }else if(n==3){
                ans+="DCCC";
            }
            n--;
           }else if(i=='9'){
            if(n==1){
                ans+="IX";
            }else if(n==2){
                ans+="XC";
            }else if(n==3){
                ans+="CM";
            }
            n--;
           }else if(i=='0'){
             n--;
           }
        }
        return ans;
    }
};