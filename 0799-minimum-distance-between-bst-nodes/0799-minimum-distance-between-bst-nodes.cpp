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
    void diff(TreeNode* root, int &prev,int &ans)
    {
        if(root==NULL)
        {
            return;
        }
        diff(root->left,prev,ans);
        if(prev!=INT_MIN)
        {
            ans=min(ans,root->val-prev);
        }
        prev=root->val;
        diff(root->right,prev,ans);
        
    }
public:
    int minDiffInBST(TreeNode* root) {
        int prev=INT_MIN;
        int ans=INT_MAX;
        diff(root,prev,ans);
        return ans;
    }
};