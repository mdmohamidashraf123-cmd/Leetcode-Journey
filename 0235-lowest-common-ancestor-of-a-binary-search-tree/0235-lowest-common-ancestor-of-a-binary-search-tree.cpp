/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root){
            return nullptr;
        }
        if(root==p||root==q){
            return root;
        }
        TreeNode* lf=lowestCommonAncestor(root->left,p,q);
        TreeNode* rt=lowestCommonAncestor(root->right,p,q);
        if((lf==p && rt==q)||(rt==p&&lf==q)){
            return root;
        }
        if((lf==p&&!rt)||(lf==q && !rt)){
            return lf;
        }
        if((rt==q && !lf)||(rt==p && !lf)){
            return rt;
        }
        
        return lf?lf:rt;
    }
};