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
    int solve(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int leftHight=solve(root->left);
        if(leftHight==-1) return -1;
        int rightHight=solve(root->right);
        if(rightHight==-1) return -1;
        if(abs(leftHight-rightHight)>1) return -1;
        return 1+max(leftHight,rightHight);
    }
    bool isBalanced(TreeNode* root) {
        return solve(root)!=-1;
    }
};