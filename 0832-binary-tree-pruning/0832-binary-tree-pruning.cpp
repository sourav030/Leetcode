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
    bool oneLeft(TreeNode* Node){
        if(!Node) return false;
        if(Node->val==1) return true;
        return oneLeft(Node->left)|| oneLeft(Node->right);
    }
    TreeNode* pruneTree(TreeNode* root) {
        if(!root) return NULL;
        if(!oneLeft(root->left)){
            root->left=NULL;
        }
        if(!oneLeft(root->right)){
            root->right=NULL;
        }

        pruneTree(root->left);
        pruneTree(root->right);
        if(root->left==NULL and root->right==NULL and root->val==0){
            return NULL;
        }
        return root;
    }
};