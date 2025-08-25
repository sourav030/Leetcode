class Solution {
public:
    vector<vector<int>> ans;

    void solve(TreeNode* root, int targetSum, vector<int>& path) {
        if (!root) return;

        path.push_back(root->val);

        if (!root->left && !root->right) { // leaf node
            if (targetSum == root->val) {
                ans.push_back(path);
            }
        } else {
            solve(root->left, targetSum - root->val, path);
            solve(root->right, targetSum - root->val, path);
        }

        path.pop_back(); // backtrack
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        solve(root, targetSum, path);
        return ans;
    }
};
