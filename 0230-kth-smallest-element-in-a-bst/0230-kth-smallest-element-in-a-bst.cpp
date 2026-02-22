class Solution {
public:
    int solve(TreeNode* root, int& k) {
        if (!root) return -1;

       
        int left = solve(root->left, k);
        if (left != -1) return left;

      
        k--;
        if (k == 0) return root->val;

       
        return solve(root->right, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        return solve(root, k);
    }
};