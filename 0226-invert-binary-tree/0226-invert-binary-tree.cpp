class Solution {
public:
    void solve(TreeNode* root) {
        if (!root) {
            return;
        }

        // swap even if one child is null
        swap(root->left, root->right);

        solve(root->left);
        solve(root->right);
    }

    TreeNode* invertTree(TreeNode* root) {
        solve(root);
        return root;
    }
};
