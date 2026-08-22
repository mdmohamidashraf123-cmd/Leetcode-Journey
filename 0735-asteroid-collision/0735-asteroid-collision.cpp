class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        //doing in place but not recommended in interviews
        int n=asteroids.size();
        int j=-1;
        for(int i=0;i<n;i++){
            int curr=asteroids[i];
            bool destroyed=false;
            while( j>=0 && asteroids[j]>0 &&curr<0){
               if(asteroids[j]<-curr){
                j--;
               }else if(asteroids[j]==-curr){
                j--;
                destroyed=true;
                break;
               }else{
                destroyed=true;
                break;
               } 
            }
            if(!destroyed){
                asteroids[j+1]=curr;
                j++;
            }
        }
       asteroids.resize(j+1);
       return asteroids;
    }
};