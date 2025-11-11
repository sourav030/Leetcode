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
    vector<int>ans;
    void inorder(TreeNode* root, int key){
        if(!root){
            return ;
        }
        inorder(root->left,key);
        if(root->val!=key){
            ans.push_back(root->val);
        }
        inorder(root->right,key);
    }
    TreeNode* solve(vector<int>ans, int start, int end){
        if(start>end){
            return nullptr;
        }
        int mid=start+(end-start)/2;
        TreeNode* root=new TreeNode(ans[mid]);
        root->left=solve(ans,start,mid-1);
        root->right=solve(ans,mid+1,end);
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        inorder(root,key);
        return solve(ans,0,ans.size()-1);
    }
};