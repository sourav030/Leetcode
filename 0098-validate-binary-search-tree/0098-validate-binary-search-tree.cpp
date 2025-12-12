class Solution {
public:
    bool solve(TreeNode* root, long right, long left){
        if(!root) return true;
        
        if(root->val <= left || root->val >= right){
            return false;
        }

        return solve(root->left, root->val, left) &&
               solve(root->right, right, root->val);
    }

    bool isValidBST(TreeNode* root) {
        return solve(root, LONG_MAX, LONG_MIN);
    }
};
