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
    TreeNode* solve(vector<int>postOrder,int &idx,int start,int end){
        if(idx<0 or start>end){
            return nullptr;
        }
        int val=postOrder[idx--];
        TreeNode* root=new TreeNode(val);
        int index=mp[val];
        root->right=solve(postOrder,idx,index+1,end);
        root->left=solve(postOrder,idx,start,index-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i=0; i<inorder.size(); i++){
            mp[inorder[i]]=i;
        }
        int idx=postorder.size()-1;
        int start=0;
        int end=idx;
        return solve(postorder,idx,start,end);
    }
};