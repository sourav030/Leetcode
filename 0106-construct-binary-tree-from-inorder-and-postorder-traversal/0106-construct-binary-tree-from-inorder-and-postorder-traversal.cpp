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
    TreeNode* solve(vector<int>& postorder, int &idx, int start, int end){
        
        if(start>end){
            return nullptr;
        }
        TreeNode* root=new TreeNode(postorder[idx--]);
        int mid=mp[root->val];
        root->right=solve(postorder,idx,mid+1,end);
        root->left=solve(postorder,idx,start,mid-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size()-1;
        int idx=n;
        for(int i=0; i<inorder.size(); i++){
            mp[inorder[i]]=i;
        }
        return solve(postorder,idx,0,n);
    }
};