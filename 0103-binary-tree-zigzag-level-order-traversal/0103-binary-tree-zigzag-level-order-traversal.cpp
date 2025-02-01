class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL) return ans;

        queue<TreeNode*> q;
        q.push(root);
        bool flag = 0; // 0 -> Left to Right, 1 -> Right to Left

        while (!q.empty()) {
            int n = q.size();
            vector<int> vec;

            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();
                vec.push_back(node->val);

                
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

          
            if (flag) {
                reverse(vec.begin(), vec.end());
            }

            ans.push_back(vec);
            flag = !flag; // Toggle flag for next level
        }
        return ans;
    }
};
