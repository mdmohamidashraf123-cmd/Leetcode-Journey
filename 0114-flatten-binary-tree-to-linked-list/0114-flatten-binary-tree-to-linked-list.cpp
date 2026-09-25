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
    TreeNode* flat(TreeNode* root){
        if(!root){
            return nullptr;
        }
        TreeNode* lf=flat(root->left);
        TreeNode* rt=flat(root->right);
        if(!lf && !rt){
            return root;
        }
        root->left=nullptr;
        root->right =lf? lf:rt;
        if(lf){
            while(lf->right){
                lf=lf->right;
            }
            lf->right=rt;
        }
        return root;
    }
    void flatten(TreeNode* root) {
       TreeNode* a=flat(root);
    }
};