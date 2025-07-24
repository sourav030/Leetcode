/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

class Solution {
  public:
   void solve(Node* root, vector<int>&ans, int level){
       if(!root){
           return;
       }
       if(level==ans.size()){
           ans.push_back(root->data);
       }
       if(root->left){
           solve(root->left, ans, level+1);
       }
       if(root->right){
           solve(root->right,ans,level+1);
       }
   }
    vector<int> leftView(Node *root) {
        // code here
        vector<int>ans;
        int level=0;
        solve(root,ans,level);
        return ans;
    }
};