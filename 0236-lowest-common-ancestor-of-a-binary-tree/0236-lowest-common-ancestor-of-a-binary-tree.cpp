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
    TreeNode* lowest(TreeNode* root, TreeNode* p , TreeNode* q){
        if(!root){
            return nullptr;
        }
        if(root==p or root==q){
            return root;
        }
        TreeNode* left=lowest(root->left,p,q);
        TreeNode* right=lowest(root->right,p,q);
        if(left and right){
            return root;
        }
        if(!left){
            return right;
        }
        else{
            return left;
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return lowest(root, p,q);
    }
};