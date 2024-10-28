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
    TreeNode* bst(vector<int>preorder, int &index, int low, int up)
    {
        if(index >= preorder.size() or low > preorder[index] or up < preorder[index])
        {
            return NULL;
        }
        TreeNode* root= new TreeNode(preorder[index++]);
        root->left=bst(preorder ,index,low, root->val);
        root->right=bst(preorder,index,  root->val , up);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index=0;
        return  bst(preorder, index, INT_MIN, INT_MAX);
        // approch
        // data is insert at left if its satify this condition data is greater than int_min and samller the root val
  // insert at right side if value is greater than root val and smaller than infinity      
    }
};