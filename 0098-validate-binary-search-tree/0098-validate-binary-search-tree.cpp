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
    bool isValidBST(TreeNode* root) {
        if(!root){
            return true;
        }
        bool c=true;
        //Check if inorder is sorted
        TreeNode* prev=nullptr;
        TreeNode* temp=root;
        while(temp){
           if(!temp->left){
              if(prev && prev->val>=temp->val){
                c=false;
              }
              prev=temp;
              temp=temp->right;
           }else{
            TreeNode* pent=temp->left;
            while(pent->right && pent->right !=temp){
                pent=pent->right;
            }
            if(!pent->right){
                pent->right=temp;
                temp=temp->left;
            }else{
                if(prev && prev->val>=temp->val){
                 c= false;
                }
                prev=temp;
                temp=temp->right;
                pent->right=nullptr;
            }
           }
        } 
      return c;
    }
};