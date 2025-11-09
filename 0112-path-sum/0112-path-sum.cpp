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
    bool solve(TreeNode* root, int sum, int target){
        if(!root){
            return false;
        }
        if(!root->left and !root->right){
            sum+=root->val;
            if(sum==target){
                return true;
            }
        }
        sum+=root->val;
        bool left=solve(root->left,sum,target);
        bool right=solve(root->right,sum,target);
        return left||right;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return solve(root,0,targetSum);
    }
};