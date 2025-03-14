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
    int count(TreeNode* root){
        if(!root) return 0;
        return 1+count(root->left)+count(root->right);
    }
    bool solve(TreeNode* root, int i,int total){
        if(!root) return true;
        if(i>total) return false;
        return solve(root->left,i*2,total) and solve(root->right,i*2+1,total);
    }
    bool isCompleteTree(TreeNode* root) {
        // queue<TreeNode*>q;
        // q.push(root);
        // bool past=false;
        // while(!q.empty()){
        //     TreeNode* node=q.front();
        //     q.pop();
        //     if(node==nullptr){
        //         past=true;
        //     }
        //     else{
        //         if(past) return false;
        //     }
        //     if(node!=nullptr){
        //     q.push(node->left);
        //     q.push(node->right);}
        // }
        // return true;
        int totalNode=count(root);
        int index=1;
        return solve(root,index,totalNode);
    }
};