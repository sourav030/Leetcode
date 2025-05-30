/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
  public:
    int ans=INT_MIN;
    void solve(Node* root, int k){
        if(!root) return;
        if(root->data>ans and root->data<=k){
            ans=root->data;
        }
        solve(root->left,k);
        solve(root->right,k);
    }
    int findMaxFork(Node* root, int k) {
        // code here
        solve(root,k);
        return ans==INT_MIN?-1:ans;
        
    }
};