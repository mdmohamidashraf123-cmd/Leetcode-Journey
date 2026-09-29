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
        vector<int>inorder;
        TreeNode* temp=root;
        while(temp){
           if(!temp->left){
              inorder.push_back(temp->val);
              temp=temp->right;
           }else{
            TreeNode* prev=temp->left;
            while(prev->right && prev->right !=temp){
                prev=prev->right;
            }
            if(!prev->right){
                prev->right=temp;
                temp=temp->left;
            }else{
                inorder.push_back(temp->val);
                temp=temp->right;
                prev->right=nullptr;
            }
           }
        } 
        //Check if inorder is sorted
        int n=inorder.size();
      for(int i=0;i<n-1;i++){
           if(!(inorder[i]<inorder[i+1])){
            return false;
           }
      }
      return true;
    }
};