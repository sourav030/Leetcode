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
    void leaf(TreeNode* root,vector<int>&ans){
        if(!root) return;
        if(!root->left and !root->right){
            ans.push_back(root->val);
        }
        leaf(root->left,ans);
        leaf(root->right,ans);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>a;
        vector<int>b;
        leaf(root1,a);
        leaf(root2,b);
        if(a.size()!=b.size()) return false;
        for(int i=0; i<a.size(); i++){
            if(a[i]!=b[i]) return false;
        }
        return true;
    }
};