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
    int solve(int &k, TreeNode* root){
        if(!root){
            return -1;
        }
        int left=solve(k,root->left);
        k--;
        if(k==0){
            return root->val;
        }
        if(left!=-1){
            return left;
        }
        int right=solve(k,root->right);
        return right;
    }
    int kthSmallest(TreeNode* root, int k) {
        return solve(k,root);
    }
};