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
    TreeNode* buildTree(vector<int>&preorder, int &idx, int mini, int maxi){
        if(idx>preorder.size()-1 or preorder[idx]<mini or preorder[idx]>maxi)
        {
            return nullptr;
        }
        TreeNode* root= new TreeNode(preorder[idx++]);
        root->left=buildTree(preorder, idx, mini,root->val);
        root->right=buildTree(preorder, idx , root->val, maxi);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int idx=0;
        return buildTree(preorder,idx, INT_MIN, INT_MAX);
    }
};