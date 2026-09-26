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
    int mps(TreeNode* root,int& maxi){
        if(!root){
            return 0;
        }
        int leftGain = max(0, mps(root->left, maxi));
        int rightGain = max(0, mps(root->right, maxi));
        int currpathsum=root->val+leftGain+rightGain;
        maxi=max(maxi,currpathsum);
        return root->val+max(leftGain,rightGain);
    }
    int maxPathSum(TreeNode* root) {
       if(!root){
         return 0;
       }
       int maxi=INT_MIN;
       int c=mps(root,maxi);
       return maxi;
    }
};