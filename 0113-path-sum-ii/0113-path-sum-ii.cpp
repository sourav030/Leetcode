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
    void solve(TreeNode* root, int sum, vector<int>arr){
        if(!root){
            return;
        }
        sum-=root->val;
        arr.push_back(root->val);
        if(sum==0 and !root->left and !root->right){
            ans.push_back(arr);
        }
        solve(root->left,sum,arr);
        solve(root->right,sum,arr);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>arr;
        solve(root,targetSum,arr);
        return ans;
    }
};