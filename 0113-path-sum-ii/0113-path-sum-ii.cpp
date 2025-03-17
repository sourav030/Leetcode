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
    vector<vector<int>>result;
    void solve(TreeNode* root, int sum, vector<int>tem,int targetSum){
        if(!root) return;
        sum+=root->val;
        tem.push_back(root->val);
        if(!root->left and !root->right){
            if(sum==targetSum){
                result.push_back(tem);
            }
                return;
        }
        solve(root->left,sum,tem,targetSum);
        solve(root->right,sum,tem,targetSum);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        int sum=0;
        vector<int>tem;
        solve(root,sum,tem,targetSum);
        return result;
    }
};