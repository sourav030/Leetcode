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
    TreeNode* first,*last,*middle,*prev;
    void Inorder(TreeNode* root){
        if(!root) return;
        Inorder(root->left);
        if(prev!=nullptr and root->val < prev->val){
            if(!first){
                first=prev;
                middle=root;
            }
            else{
                last=root;
            }
        }
        prev=root;
        Inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
       prev=first=last=middle=nullptr;
      
        Inorder(root);
        if(first and last) swap(first->val,last->val);
       else if(first and middle) swap(first->val,middle->val);
    }
};