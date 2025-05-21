/* Node structure
struct Node
{
    int data;
    Node* left, *right;
}; */

/* Given two trees, should return true if they are
   mirror of each other. */
class Solution {
  public:
    int solve(Node*a, Node*b){
        if(!a and !b){
            return 1;
        }
        if(!a or !b) return 0;
        if(a->data!=b->data) return  0;
        int left=solve(a->left,b->right);
        int right=solve(a->right,b->left);
        if(left and right) return 1;
        else{
            return 0;
        }
    }
    int areMirror(Node* a, Node* b) {
        // Your code here
        return solve(a,b);
    }
};