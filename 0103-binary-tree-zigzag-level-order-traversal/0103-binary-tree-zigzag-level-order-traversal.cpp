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
        if(!root){
            vector<vector<int>>ans;
            return ans;
        }
        queue<TreeNode*>q; //  we need to performa level order travserl
        bool track=0;
        vector<vector<int>>ans;
        q.push(root);
        while(!q.empty()){
            vector<int>arr;
            int n=q.size(); // each how many element are present
            for(int i=0; i<n; i++){
                TreeNode* node=q.front();
                q.pop();
                arr.push_back(node->val);
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            if(!track){
                ans.push_back(arr);
                track=!track;
            }
            else{
                reverse(arr.begin(),arr.end());
                ans.push_back(arr);
                track=!track;
            }
        }
        return ans;
    }
};