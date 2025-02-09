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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root) {
            TreeNode* newNode=new TreeNode(val);
            return newNode;
        }
        TreeNode* root1=root;
        while(root){
            if(root->val < val){
                if(root->right!=NULL){
                    root=root->right;
                }
                else{
                    TreeNode* newNode=new TreeNode(val);
                    root->right=newNode;
                    break;
                }
            }
            else{
                if(root->left!=NULL){
                    root=root->left;
                }
                else{
                    TreeNode* newNode=new TreeNode(val);
                    root->left=newNode;
                    break;
                }
            }
        }
        return root1;
    }
};