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
    TreeNode* solve(vector<int>preorder, int &idx, int start, int end){
        if(idx>=preorder.size() or start>end){
            return nullptr;
        }
        int val=preorder[idx++];
        int indx=mp[val];
        TreeNode* root=new TreeNode(val);
        root->left=solve(preorder,idx,start,indx-1);
        root->right=solve(preorder,idx,indx+1,end);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0; i<inorder.size(); i++){
            mp[inorder[i]]=i;
        }
        int idx=0;
        int n=preorder.size()-1;
        int s=0;
        return solve(preorder,idx,s,n);

    }
};