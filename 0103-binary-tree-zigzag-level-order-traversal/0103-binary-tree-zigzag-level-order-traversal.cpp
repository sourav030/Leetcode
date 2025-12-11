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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(!root){
            return ans;
        }
        queue<TreeNode*>q;
        q.push(root);
        bool order=true;
        while(!q.empty()){
            int n=q.size();
            vector<int>arr;
            for(int i=0; i<n; i++){
                TreeNode* node=q.front();
                q.pop();
                arr.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            if(!order){
                reverse(arr.begin(),arr.end());
            }
            ans.push_back(arr);
            order=!order;
        }
        return ans;
    }
};