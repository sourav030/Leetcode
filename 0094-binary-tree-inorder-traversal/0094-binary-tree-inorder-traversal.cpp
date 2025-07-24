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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        stack<TreeNode*>st;
        while(root or !st.empty()){
            while(root){
                st.push(root);
                root=root->left;
            }
            if(!st.empty()){
                TreeNode* node=st.top();
                st.pop();
                ans.push_back(node->val);
                root=node->right;
            }
        }
        return ans;
    }
};