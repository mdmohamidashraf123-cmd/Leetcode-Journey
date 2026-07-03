class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        int n=arr.size();
        int st=0;
        int end=n-1;
        if(st==end){
            return st;
        }
        if(arr[0]>arr[1]){
            return 0;
        }else if(arr[n-1]>arr[n-1-1]){
            return n-1;
        }
        st++;
        end--;
        while(st<=end){
            int mid=st+(end-st)/2;
            if(arr[mid]<arr[mid+1]){
                st=mid+1;
            }else if(arr[mid]<arr[mid-1]){
                end=mid-1;
            }else{
               return mid;
            }
        }
        return st;
    }
};