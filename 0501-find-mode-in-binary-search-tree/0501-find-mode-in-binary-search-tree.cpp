class Solution {
public:
    void solve(TreeNode* root, unordered_map<int, int>& mp) {
        if (!root) return;
        mp[root->val]++;
        solve(root->left, mp);
        solve(root->right, mp);
    }

    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> mp;
        solve(root, mp);

        int maxFreq = 0;
        for (auto& pair : mp) {
            maxFreq = max(maxFreq, pair.second);
        }

        vector<int> result;
        for (auto& pair : mp) {
            if (pair.second == maxFreq) {
                result.push_back(pair.first);
            }
        }

        return result;
    }
};
