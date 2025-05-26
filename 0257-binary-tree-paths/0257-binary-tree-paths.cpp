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
   vector<string>ans;
   void solve(TreeNode* root, string st){
    if(!root) return;
    st+=to_string(root->val)+"->";
    if(!root->left and !root->right){
        st.pop_back();
        st.pop_back();
        ans.push_back(st);
        return;
    }
    solve(root->left,st);
    solve(root->right,st);
   }
    vector<string> binaryTreePaths(TreeNode* root) {
        string ans1="";
        solve(root,ans1);
        return ans;
    }
};