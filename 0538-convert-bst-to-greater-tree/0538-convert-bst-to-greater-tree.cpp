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
    vector<int>Inorder;
    void solve(TreeNode* root){
        if(!root) return;
        solve(root->left);
        Inorder.push_back(root->val);
        solve(root->right);
    }
    int find(int value){
        int sum=0;
        for(int i=0; i<Inorder.size(); i++){
            if(Inorder[i]>=value){
                sum+=Inorder[i];
            }
        }
        return sum;
    }
    TreeNode* convertBST(TreeNode* root) {
        if(!root) return nullptr;
        solve(root);
        queue<TreeNode*>q;
        TreeNode* curr=root;
        q.push(root);
        while(!q.empty()){
            TreeNode* Node=q.front();
            q.pop();
            int val=find(Node->val);
            Node->val=val;
            if(Node->left){
                q.push(Node->left);
            }
            if(Node->right){
                q.push(Node->right);
            }
        }
        return curr;
    }
};