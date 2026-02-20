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
    TreeNode* solve(vector<int>&preorder,int &idx, int maxi, int mini){
            if(idx>=preorder.size() or preorder[idx]<mini or preorder[idx]>maxi){
                return nullptr;
            }
            TreeNode* root=new TreeNode(preorder[idx++]);
            root->left=solve(preorder,idx,root->val,mini);
            root->right=solve(preorder,idx,maxi,root->val);
            return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int idx=0;
        int maxi=INT_MAX;
        int mini=INT_MIN;
        return solve(preorder,idx,maxi,mini);
    }
};