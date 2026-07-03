class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n=arr.size();
        int st=0;
        int end=n-1;
        while(st<=end){
            int mid=st+(end-st)/2;
            if(mid==0){
                if(arr[mid]>arr[1]){
                    return mid;
                }
            }else if(mid==n-1){
                if(arr[mid]>arr[n-2]){
                    return mid;
                }
            }
            if(arr[mid]<=arr[mid+1]){
                    st=mid+1;
            }else if(arr[mid]<arr[mid-1]){
                end=mid-1;
            }else{
                return mid;
            }
        }
        return -1;
    }
};