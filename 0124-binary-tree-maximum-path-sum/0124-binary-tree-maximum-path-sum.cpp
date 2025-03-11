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
    int maxsum=INT_MIN;
    int solve(TreeNode* root){
        if(!root) return 0;
        int l=solve(root->left);
        int r=solve(root->right);

        int case1=max(l,r)+root->val;
        int case2=l+r+root->val;
        int case3=root->val;
        maxsum=max({case1,case2,case3,maxsum});
        return max(case1,case3);

    }
    int maxPathSum(TreeNode* root) {
      solve(root);
      return maxsum;   
    }
};