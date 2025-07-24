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
    bool solve(TreeNode* root1, TreeNode* root2){
        if(!root1 and !root2){
            return true;
        }
        if(!root1 or !root2){
            return false;
        }
        if(root1->val!=root2->val){
            return false;
        }
        return solve(root1->left,root2->left) and solve(root1->right,root2->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root){
            return false;
        }
        if(root->val==subRoot->val){
            if(solve(root,subRoot)){
                return true;
            }
        }
        bool left=isSubtree(root->left,subRoot);
        bool right=isSubtree(root->right,subRoot);
        return left or right;
    }
};