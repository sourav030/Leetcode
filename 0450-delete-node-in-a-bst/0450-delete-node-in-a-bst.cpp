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
    void build(TreeNode* root, vector<int>&nums, int key){
        if(!root) return;
        build(root->left, nums,key);
        if(root->val!=key){
            nums.push_back(root->val);
        }
        build(root->right,nums,key);
    }
    TreeNode* tree(vector<int>&nums, int start, int end){
        if(start>end) return nullptr;
        int mid=start+(end-start)/2;
        TreeNode* root=new TreeNode (nums[mid]);
        root->left=tree(nums,start,mid-1);
        root->right=tree(nums,mid+1,end);
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        vector<int>nums;
        build(root,nums,key);
        int n=nums.size()-1;
        return tree(nums,0,n);
    }
};