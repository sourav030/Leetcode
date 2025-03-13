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

    TreeNode* solve(vector<int>& preorder,unordered_map<int,int>& mp,int start,int end,int &index){
        if(start>end) return nullptr;
        int element=preorder[index];
        index++;
        TreeNode* root=new TreeNode(element);
        int pos=mp[element];
        root->left=solve(preorder,mp,start,pos-1,index);
        root->right=solve(preorder,mp,pos+1,end,index);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>mp;
        for(int i=0; i<inorder.size(); i++){
            mp[inorder[i]]=i;
        }
        int index=0;
        return solve(preorder,mp,0,inorder.size()-1,index);
    }
};