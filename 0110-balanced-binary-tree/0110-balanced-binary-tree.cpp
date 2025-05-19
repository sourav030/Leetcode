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
    bool value=true;
    int height(TreeNode* root){
        if(!root) return 0;
        int left=height(root->left);
        int right=height(root->right);
        if(abs(left-right)>1) value=false;
        return max(left,right)+1;
    }
    bool isBalanced(TreeNode* root) {
        height(root);
        return value;
    }
};