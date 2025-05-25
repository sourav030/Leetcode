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
    TreeNode* solve(vector<int>& preorder,int &idx, int start, int end){
        if(idx>=preorder.size() or start>end){
            return nullptr;
        }
        int mid=mp[preorder[idx]];
        TreeNode* root=new TreeNode(preorder[idx++]);
        root->left=solve(preorder,idx,start,mid-1);
        root->right=solve(preorder,idx,mid+1,end);
        return root;
        
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0; i<inorder.size(); i++){
            mp[inorder[i]]=i;
        }
        int start=0;
        int end=inorder.size()-1;
        int idx=0;
        return solve(preorder,idx,start,end);
    }
};