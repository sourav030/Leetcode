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
    vector<vector<int>>ans;
    void solve(TreeNode* root, int targetSum, vector<int>path){
        if(!root){
            return;
        }
        if(!root->left and !root->right){
            int val=targetSum-root->val;
            path.push_back(root->val);
            if(val==0){
                ans.push_back(path);
            }
            return;
        }
        path.push_back(root->val);
        solve(root->left, targetSum-root->val,path);
        solve(root->right,targetSum-root->val,path);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>path;
        solve(root,targetSum,path);
        return ans;
    }
};