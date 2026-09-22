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
    //Optimal Approach
    int height(TreeNode* root){
        if(!root){
            return 0;
        }
        int d=height(root->left);
        if(d==-1){
            return d;
        }
        int e=height(root->right);
        if(e==-1){
            return -1;
        }
        if(abs(d-e)>1){
            return -1;
        }
        return 1+ max(d,e);
    }
    bool isBalanced(TreeNode* root) {
        int x=height(root);
        return x!=-1;
    }
};