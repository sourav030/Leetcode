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
    TreeNode* solve(vector<int>&preorder, int &idx, int start, int end){
        if(start>end){
            return nullptr;
        }
        TreeNode* root=new TreeNode(preorder[idx++]);
        int mid=mp[root->val];
        root->left=solve(preorder,idx,start,mid-1);
        root->right=solve(preorder,idx,mid+1,end);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int idx=0;
        int n=inorder.size()-1;
        for(int i=0; i<inorder.size(); i++){
            mp[inorder[i]]=i;
        }
        return solve(preorder,idx,0,n);
    }
};