class Solution {
public:
    map<int, map<int, multiset<int>>> nodes;

    void dfs(TreeNode* root, int row, int col) {
        if (!root) return;
        nodes[col][row].insert(root->val);
        dfs(root->left, row + 1, col - 1);
        dfs(root->right, row + 1, col + 1);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        dfs(root, 0, 0);  // root is at (row=0, col=0)
        
        vector<vector<int>> ans;
        for (auto& [col, rowMap] : nodes) {
            vector<int> colVals;
            for (auto& [row, vals] : rowMap) {
                colVals.insert(colVals.end(), vals.begin(), vals.end());
            }
            ans.push_back(colVals);
        }
        return ans;
    }
};
