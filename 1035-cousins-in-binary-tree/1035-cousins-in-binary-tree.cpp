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
       pair<int, int> level(TreeNode* root, int x) {
        int depth = 0;
        queue<pair<TreeNode*, int>> q; 
        q.push({root, -1});

        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                auto [node, parent] = q.front();
                q.pop();

                if (node->val == x) {
                    return {depth, parent};
                }

                if (node->left) q.push({node->left, node->val});
                if (node->right) q.push({node->right, node->val});
            }
            depth++;
        }
        return {-2, -2}; 
    }
    bool isCousins(TreeNode* root, int x, int y) {
        pair<int,int>p1=level(root,x);
        pair<int,int>p2=level(root,y);
        if(p1.first==p2.first and p1.second!=p2.second){
            return true;
        }
        else{
            return false;
        }
    }
};