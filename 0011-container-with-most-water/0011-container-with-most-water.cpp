class Solution {
public:
    int maxArea(vector<int>& height) {
       int i=0;
       int j=height.size()-1;
       int ma=0;
       while(i<j){
          int h=min(height[i],height[j]);
          int w=j-i;
          int area=h*w;
          ma=max(ma,area);
          if(h==height[i]){
            i++;
          }else{
            j--;
          }
       }
       return ma;
    }
};