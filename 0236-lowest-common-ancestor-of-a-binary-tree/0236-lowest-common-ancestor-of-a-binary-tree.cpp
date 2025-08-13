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
            return nullptr;
         }
         if(root==p){
            return root;
         }
         if(root==q){
            return root;
         }
         TreeNode* left1=solve(root->left,p,q);
         TreeNode* right1=solve(root->right,p,q);
         if(left1 and right1){
            return root;
         }
         else if(left1){
            return left1;
         }
         else{
            return right1;
         }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        return solve(root, p,q);
    }
};