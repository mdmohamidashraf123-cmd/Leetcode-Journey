class Solution {
public:
    void getino(TreeNode* root, TreeNode*& pre, TreeNode*& first, TreeNode*& second) {
        if (!root) return;

        getino(root->left, pre, first, second);

        // Check if the BST property is violated (prev value > current value)
        if (pre && pre->val > root->val) {
            // First time finding a violation
            if (!first) {
                first = pre;
            }
            // 'second' is always updated to current root on any violation
            second = root;
        }
        
        pre = root; // Move pre to current node

        getino(root->right, pre, first, second);
    }

    void recoverTree(TreeNode* root) {
        //using recursion
        TreeNode* pre = nullptr;
        TreeNode* first = nullptr;
        TreeNode* second = nullptr;

        getino(root, pre, first, second);

        // Swap back the values of the two mismatched nodes
        if (first && second) {
            swap(first->val, second->val);
        }
    }
};