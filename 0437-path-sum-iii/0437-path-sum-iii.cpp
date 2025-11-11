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
    int count=0;
    void Check(TreeNode* root, int targetSum, long long sum){
        if(!root) return;
        sum+=root->val;
        if(sum==targetSum) count++;
        Check(root->left,targetSum,sum);
        Check(root->right,targetSum,sum);
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(!root){
            return 0;
        }
        Check(root,targetSum,0);
        int a=pathSum(root->left,targetSum);
        int b=pathSum(root->right,targetSum);
        return count;
    }
};