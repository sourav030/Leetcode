class Solution {
public:
    int ans = -1;

    void solve(TreeNode* root, int &k) {
        if (!root || k == 0) return;

        solve(root->left, k);
        k--;
        if (k == 0) {
            ans = root->val;
            return;
        }
        solve(root->right, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        solve(root, k);
        return ans;
    }
};
