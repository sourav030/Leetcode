class Solution {
public:
    int solve(TreeNode* root, int target, long long sum) {
        if (!root) return 0;
        sum += root->val;
        int count = (sum == target) ? 1 : 0;
        count += solve(root->left, target, sum);
        count += solve(root->right, target, sum);
        return count;
    }

    int pathSum(TreeNode* root, int targetSum) {
        if (!root) return 0;
        int fromRoot = solve(root, targetSum, 0);
        int fromLeft = pathSum(root->left, targetSum);
        int fromRight = pathSum(root->right, targetSum);
        return fromRoot + fromLeft + fromRight;
    }
};
