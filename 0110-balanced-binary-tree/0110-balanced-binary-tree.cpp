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
    int height(TreeNode* root,bool& f){
        if(!root){
            return 0;
        }
        int d=height(root->left,f);
        int e=height(root->right,f);
        if(abs(d-e)>1){
            f=false;
        }
        return 1+ max(d,e);
    }
    bool isBalanced(TreeNode* root) {
        bool f=true;
        int x=height(root,f);
        return f;
    }
};