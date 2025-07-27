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
    
    bool solve(TreeNode* root , int k){
        if(!root){
            return false;
        }
        if(mp.find(k-root->val)!=mp.end()){
            return true;
        }
        mp[root->val]=1;
        bool left=solve(root->left,k);
        bool right=solve(root->right,k);
        return left|| right;
    }
    bool findTarget(TreeNode* root, int k) {
        
        return solve(root,k);
    }
};