/*

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

*/

class Solution {
  public:
    bool solve(Node* root){
        if(!root){
            return true;
        }
        if(!root->left and !root->right){
            return true;
        }
        int val=root->left?root->left->data:0;
        int val2=root->right?root->right->data:0;
        if(root->data!=val+val2){
            return false;
        }
        return solve(root->left) and solve(root->right);
    }
    int isSumProperty(Node *root) {
        // code here
        return solve(root);
        
    }
};