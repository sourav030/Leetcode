class Solution {
public:
    vector<int> validNodes;

 
    void preorder(TreeNode* root, int low, int high) {
        if (!root) return;
        if (root->val >= low && root->val <= high) {
            validNodes.push_back(root->val);
        }
        preorder(root->left, low, high);
        preorder(root->right, low, high);
    }

  
    TreeNode* insertBST(TreeNode* root, int val) {
        if (!root) return new TreeNode(val);

        if (val < root->val)
            root->left = insertBST(root->left, val);
        else
            root->right = insertBST(root->right, val);

        return root;
    }

   
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        preorder(root, low, high); // Step 1: collect values

        TreeNode* newRoot = nullptr;

        for (int val : validNodes) {
            newRoot = insertBST(newRoot, val); // Step 2: rebuild
        }

        return newRoot;
    }
};
