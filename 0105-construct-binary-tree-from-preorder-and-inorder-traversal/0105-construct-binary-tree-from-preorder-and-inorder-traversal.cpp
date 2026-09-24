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
    TreeNode* bt(int prestart,int instart,int inend,int preend,vector<int>& preorder,vector<int>& inorder){
        if(prestart>=preend){
            return nullptr;
        }
        if(preend-prestart==1){
            TreeNode* w=new TreeNode(preorder[prestart]);
            return w;
        }
        int root=preorder[prestart];
        int c=0;
        for(int i=instart;i<inend;i++){
            if(inorder[i]==root){
                break;
            }
            c++;
        }
        int old_preend=preend;
        int old_inend=inend;
        preend=c+prestart+1;
        inend=instart+c;
        TreeNode* lf=bt(prestart+1,instart,inend,preend,preorder,inorder);
        TreeNode* rt=bt(preend,instart+c+1,old_inend,old_preend,preorder,inorder);
        TreeNode* parent=new TreeNode(root);
        parent->left=lf;
        parent->right=rt;
        return parent;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return  bt(0,0,inorder.size(),preorder.size(),preorder,inorder);
    }
};