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
    long long ans=0;
    void solve(TreeNode* root, long long sum){
        if(!root){
            return;
        }
        if(!root->left and !root->right){
            sum=sum*10+root->val;
              ans+=sum;
             
        }
        long long a=sum*10+root->val;
        solve(root->left,a);
        solve(root->right,a);
    }
    int sumNumbers(TreeNode* root) {
        long long sum=0;
        solve(root,sum);
        return ans;
    }
};