class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int st=0;
        int n=nums.size();
        int end=nums.size()-1;
        int a=-1;
        int b=-1;
        while(st<=end){
            int mid=st+(end-st)/2;
            if(nums[mid]==target){
                if(mid!=0 && nums[mid-1]==target){
                    end=mid-1;
                }else{
                    a=mid;
                    break;
                }
            }else if(nums[mid]>target){
              end=mid-1;
            }else{
                st=mid+1;
            }
        }
        st=0;
        end=n-1;
        while(st<=end){
            int mid=st+(end-st)/2;
            if(nums[mid]==target){
                if(mid!=n-1 && nums[mid+1]==target){
                    st=mid+1;
                }else{
                    b=mid;
                    break;
                }
            }else if(nums[mid]>target){
              end=mid-1;
            }else{
                st=mid+1;
            }
        }
        return {a,b};
    }
};