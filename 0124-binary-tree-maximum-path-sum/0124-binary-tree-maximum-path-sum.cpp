class Solution {
public:
    int ans = INT_MIN;

    int solve(TreeNode* root) {
        if (!root) return 0;

        int left = max(0, solve(root->left));   // ignore negative
        int right = max(0, solve(root->right)); // ignore negative

        // Path passing through current node
        ans = max(ans, left + right + root->val);

        // Return max downward path
        return root->val + max(left, right);
    }

    int maxPathSum(TreeNode* root) {
        solve(root);
        return ans;
    }
};
