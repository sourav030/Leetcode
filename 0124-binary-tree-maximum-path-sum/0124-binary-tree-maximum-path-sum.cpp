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
    int ans=INT_MIN;
    int solve(TreeNode* root){
        if(!root) return 0;
        int lef=max(0,solve(root->left));
        int rig=max(0,solve(root->right));
        int sum=lef+root->val;
        sum=max(sum,max(rig+root->val,lef+rig+root->val));
        ans=max(sum,ans);
        return max(lef,rig)+root->val;
    }
    int maxPathSum(TreeNode* root) {
        solve(root);
        return ans;
    }
};