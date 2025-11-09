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
        if(start>end or idx>=preorder.size()){
            return nullptr;
        }
        int index=mp[preorder[idx]];
        TreeNode* root=new TreeNode(preorder[idx++]);
        root->left=solve(preorder,idx,start,index-1);
        root->right=solve(preorder,idx,index+1,end);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0; i<inorder.size(); i++){
            mp[inorder[i]]=i;
        }
        int idx=0;
        return solve(preorder,idx,0,inorder.size()-1);
    }
};