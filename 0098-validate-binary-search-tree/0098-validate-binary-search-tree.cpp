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
    bool solve(TreeNode* root, long long mini, long long maxi){
        if(!root){
            return true;
        }
        if(root->val<=mini or root->val>=maxi){
            return false;
        }
        bool left=solve(root->left,mini,root->val);
        bool right=solve(root->right,root->val,maxi);
        return left and right;
    }
    bool isValidBST(TreeNode* root) {
        if(root and !root->left and !root->right){
            return true;
        }
        return solve(root, LLONG_MIN, LLONG_MAX);
    }
};