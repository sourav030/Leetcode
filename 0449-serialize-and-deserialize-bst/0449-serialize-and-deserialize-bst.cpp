/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string (using preorder traversal).
    string serialize(TreeNode* root) {
        string ans = "";
        preorder(root, ans);
        return ans;
    }

    void preorder(TreeNode* root, string &ans) {
        if (!root) return;
        ans += to_string(root->val) + " ";
        preorder(root->left, ans);
        preorder(root->right, ans);
    }

    // Decodes your encoded data to tree (using BST bounds method).
    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;
        
        vector<int> preorder;
        stringstream ss(data);
        string temp;
        while (ss >> temp) {
            preorder.push_back(stoi(temp));
        }
        
        int idx = 0;
        return buildTree(preorder, idx, INT_MIN, INT_MAX);
    }

    TreeNode* buildTree(vector<int>& preorder, int &idx, int mini, int maxi) {
        if (idx >= preorder.size() || preorder[idx] < mini || preorder[idx] > maxi) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder[idx++]);
        root->left = buildTree(preorder, idx, mini, root->val);
        root->right = buildTree(preorder, idx, root->val, maxi);
        return root;
    }
};
