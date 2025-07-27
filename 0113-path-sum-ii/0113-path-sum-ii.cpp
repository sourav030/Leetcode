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
    void solve(TreeNode* root,int sum, int targetSum, vector<int>pathSum){
        if(!root){
            return;
        }
        sum+=root->val;
        pathSum.push_back(root->val);
        if(!root->left and !root->right){
            if(sum==targetSum){
                ans.push_back(pathSum);
            }
        }
        solve(root->left,sum,targetSum,pathSum);
        solve(root->right,sum,targetSum,pathSum);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>path;
        int sum=0;
        solve(root,sum,targetSum,path);
        return ans;
    }
};