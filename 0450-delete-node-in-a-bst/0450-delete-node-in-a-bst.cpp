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
    TreeNode* bst(vector<int>&ans, int start,int end){
        if(end<start){
            return nullptr;
        }
        int mid=start+(end-start)/2;
        TreeNode* root=new TreeNode(ans[mid]);
        root->left=bst(ans, start,mid-1);
        root->right=bst(ans,mid+1,end);
        return root;
    }
    void inorder(TreeNode* root, vector<int>&arr, int key){
        if(!root){
            return;
        }
        inorder(root->left,arr,key);
        if(root->val!=key){
            arr.push_back(root->val);
        }
        inorder(root->right,arr,key);
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        vector<int>ans;
        inorder(root,ans,key);
        int n=ans.size()-1;
        return bst(ans,0,n);

    }
};