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
   
    void inorder(TreeNode* root,vector<int>&Array){
        if(!root){
            return;
        }
        inorder(root->left,Array);
        Array.push_back(root->val);
        inorder(root->right,Array);
    }
    TreeNode* build(vector<int>nums, int start, int end){
        if(start>end){
            return nullptr;
        }
        int mid=start+(end-start)/2;
        TreeNode* root=new TreeNode(nums[mid]);
        root->left=build(nums,start,mid-1);
        root->right=build(nums, mid+1,end);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>Array;
        inorder(root,Array);
        int n=Array.size()-1;
        return build(Array,0,n);
    }
};