/* Tree node structure  used in the program
 struct Node
 {
     int data;
     Node* left, *right;
}; */

class Solution {
  public:
    int sum=0;
    void solve(Node* root, int ans){
        if(!root){
            return ;
        }
        ans=ans*10+root->data;
        if(!root->left and !root->right){
            sum+=ans;
            return;
        }
       
        solve(root->left,ans);
        solve(root->right,ans);
    }
    int treePathsSum(Node *root) {
        // code here
        int ans=0;
        solve(root,ans);
        return sum;
    }
};