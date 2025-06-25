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
    void solve(TreeNode* root, vector<int>&nums){
        if(!root) return;
        solve(root->left, nums);
        nums.push_back(root->val);
        solve(root->right,nums);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int>nums;
        solve(root,nums);
        int start=0;
        int end=nums.size()-1;
        if(nums.size()<2) return false;
        while(start<end){
            int sum=nums[start]+nums[end];
            if(sum>k){
                end--;
            }
            else if(sum<k){
                start++;
            }
            else{
                return true;
            }
        }
        return false;
    }
};