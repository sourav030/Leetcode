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
    bool solve(TreeNode* p,TreeNode* q){
        if(p and !q) return false;
        if(!p and q) return false;
        if(p==NULL and q==NULL) return true;
        if(p->val!=q->val) return false;
        if(solve(p->left,q->left) and solve(p->right,q->right)){
            return true;
        }
        else{
            return false;
        }
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return solve(p,q);
    }
};