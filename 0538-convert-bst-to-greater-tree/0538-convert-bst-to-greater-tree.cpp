class Solution {
public:
    int sum = 0;

    void reverseInorder(TreeNode* root) {
        if (!root) return;

        reverseInorder(root->right);
        sum += root->val;
        root->val = sum;
        reverseInorder(root->left);
    }

    TreeNode* convertBST(TreeNode* root) {
        reverseInorder(root);
        return root;
    }
};
