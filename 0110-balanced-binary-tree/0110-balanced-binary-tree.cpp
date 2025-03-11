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
    int hight(TreeNode* root){
        if(!root) return 0;
        int lefts=hight(root->left);
        int rights=hight(root->right);
        if(lefts==-1 or rights==-1 or abs(lefts-rights)>1){
            return -1;
        }
        return 1+max(lefts,rights);
    }
    bool isBalanced(TreeNode* root) {
        return hight(root)!=-1;
    }
};