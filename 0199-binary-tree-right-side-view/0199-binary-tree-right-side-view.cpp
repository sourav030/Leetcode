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
    void leftside(TreeNode* root,int level,vector<int>&ans)
{
    if(root==NULL)
    {
        return;
    }
    if(level==ans.size())
    {
        ans.push_back(root->val);
    }
    leftside(root->right,level+1,ans);
    leftside(root->left,level+1,ans);
    
}
public:
    vector<int> rightSideView(TreeNode* root) {
        int level=0;
        vector<int>an;
        leftside(root,level,an);
        return an;
    }
};