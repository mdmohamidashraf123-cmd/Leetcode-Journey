/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* bst(int st,int end,vector<int>& nums){
        if(st>end){
            return nullptr;
        }
        if(st==end){
            return new TreeNode(nums[st]);
        }
        int mid=st+(end-st)/2;
        TreeNode* lf=bst(st,mid-1,nums);
        TreeNode* rt=bst(mid+1,end,nums);
        TreeNode* root=new TreeNode(nums[mid]);
        root->left=lf;
        root->right=rt;
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size()==0){
            return nullptr;
        }
        int st=0;
        int end=nums.size()-1;
        return bst(st,end,nums);
    }
};