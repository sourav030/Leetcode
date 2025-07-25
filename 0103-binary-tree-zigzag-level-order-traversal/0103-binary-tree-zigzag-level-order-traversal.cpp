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
        if(!root ){
            vector<vector<int>>ar;
            return ar;
        }
        queue<TreeNode*>q;
        q.push(root);
        vector<vector<int>>ans;
        bool flag=0;
        while(!q.empty()){
            int n=q.size();
            vector<int>arr;
            for(int i=0; i<n; i++){
                TreeNode* node=q.front();
                arr.push_back(node->val);
                q.pop();
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            if(flag){
                reverse(arr.begin(),arr.end());
            }
            flag=!flag;
            ans.push_back(arr);
        }
        return ans;
    }
};