class Solution {
public:
    void merge(vector<int>& arr ,int st,int mid,int end){
        int left=st;
        int right=mid+1;
        vector<int>temp;
        while(left<=mid && right<=end){
        if (arr[left]>arr[right]){
            temp.push_back(arr[right]);
            right++;
        }else{
            temp.push_back(arr[left]);
            left++;
        }
        }
        while(left<=mid){
            temp.push_back(arr[left]);
            left++;
        }
        while(right<=end){
            temp.push_back(arr[right]);
            right++;
        }
        for(int i=st;i<=end;i++){
            arr[i]=temp[i-st];
        }
        return;
    }
    void mergesort(vector<int>& nums ,int st,int end){
         if(st>=end){
            return;
         }
         int mid=st+(end-st)/2;
         mergesort(nums,st,mid);
         mergesort(nums,mid+1,end);
         merge(nums,st,mid,end);
    }
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        mergesort(nums,0,n-1);
        return nums[n-k];
    }
};