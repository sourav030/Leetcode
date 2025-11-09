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
    vector<vector<int>> ans;
    
    void solve(TreeNode* root, int target, int sum, vector<int>& path) {
        if (!root) return;
        
        sum += root->val;
        path.push_back(root->val);
        
        // If it's a leaf node and sum equals target
        if (!root->left && !root->right && sum == target) {
            ans.push_back(path);
        }
        
        solve(root->left, target, sum, path);
        solve(root->right, target, sum, path);
        
        // backtrack
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        solve(root, targetSum, 0, path);
        return ans;
    }
};
