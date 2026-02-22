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
    unordered_map<int,int>mp;
    bool solve(TreeNode* root,int sum){
        if(!root){
            return false;
        }
        if(mp.find(sum-root->val)!=mp.end()){
            return true;
        }
        mp[root->val]=1;
        return solve(root->left,sum)|| solve(root->right,sum);
    }
    bool findTarget(TreeNode* root, int k) {
        return solve(root,k);
    }
};