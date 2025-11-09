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
    TreeNode* solve(vector<int>&postOrder, int &idx, int start,int end){
        if(start>end or idx<0){
            return nullptr;
        }
        int val=postOrder[idx];
        int index=mp[postOrder[idx--]];
        TreeNode* root=new TreeNode(val);
        root->right=solve(postOrder,idx,index+1,end);
        root->left=solve(postOrder,idx,start,index-1);
        return root;

    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i=0; i<inorder.size(); i++){
            mp[inorder[i]]=i;
        }
        int n=inorder.size()-1;
        int idx=n;
        return solve(postorder,idx,0,n);
    }
};