class Solution {
public:
    //SECOND HARD PROBLEM SOLVED ON MY OWN !!
    //Improve time management
    int trap(vector<int>& height) {
        int n=height.size();
        int i=0;
        int j=0;
        int ans=0;
        while(j<n){
            int k=0;
           while(j<n && i<j && height[j]<height[i]){
            k+=height[i]-height[j];
            j++;
           }
           if(j==n){
            k=0;
            break;
           }
           ans+=k;
           i=j;
           j=i+1;
        }
        j=n-1;
        int max=height[j];
        while(j>i){
          if(height[j]>max){
            max=height[j];
          }else{
            ans+=max-height[j];
          }
          j--;
        }
        return ans;
    }
};