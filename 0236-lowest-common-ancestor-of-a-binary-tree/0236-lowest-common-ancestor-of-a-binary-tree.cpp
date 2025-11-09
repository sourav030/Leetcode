/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* solve(TreeNode* root, TreeNode* p, TreeNode* q){
        if(!root){
            return root;
        }
        if(root==p){
            return root;
        }
        if(root==q){
            return root;
        }
        TreeNode* left=solve(root->left,p,q);
        TreeNode* right=solve(root->right,p,q);
        if(left and right){
            return root;
        }
        if(left){
            return left;
        }
        else
           return right;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return solve(root,p,q);
    }
};