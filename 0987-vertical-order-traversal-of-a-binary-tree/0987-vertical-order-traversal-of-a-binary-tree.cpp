class Solution {
public:
    map<int, map<int, vector<int>>> mp;
    vector<vector<int>> ans;

    void solve(TreeNode* root, int col, int row) {
        if (!root) return;

        mp[col][row].push_back(root->val);

        solve(root->left, col - 1, row + 1);
        solve(root->right, col + 1, row + 1);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        solve(root, 0, 0);

        for (auto &colPair : mp) {
            vector<int> column;
            for (auto &rowPair : colPair.second) {
                auto &vals = rowPair.second;
                sort(vals.begin(), vals.end());  
                column.insert(column.end(), vals.begin(), vals.end());
            }
            ans.push_back(column);
        }
        return ans;
    }
};
