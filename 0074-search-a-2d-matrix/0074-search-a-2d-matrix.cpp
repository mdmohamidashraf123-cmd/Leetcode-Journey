class Solution {
public:
    bool search(vector<vector<int>>& matrix,int midr, int target){
        int st=0;
        int end=matrix[midr].size();
        while(st<=end){
            int mid=(end-st)/2 + st;
            if(matrix[midr][mid]==target){
                return true;
            }else if(matrix[midr][mid]<target){
                st=mid+1;
            }else{
                end=mid-1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        int str=0;
        int endr=m-1;
        while(str<=endr){
           int midr=str+(endr-str)/2;
           int stc=0;
           int endc=n-1;
           if(matrix[midr][0]<=target && matrix[midr][n-1]>=target){
             return search(matrix,midr,target);
           }else if(matrix[midr][0]>target){
             endr=midr-1;
           }else{
            str=midr+1;
           }
        }
        return false;
    }
};