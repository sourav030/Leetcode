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
    // Function to check if S is a subtree of tree T.
    bool identical(Node* root1,Node* root2){
        if(!root1 and !root2) return true;
        if(!root1 or !root2) return false;
        if(root1->data!=root2->data) return false;
        return identical(root2->left,root2->left) and identical(root1->right,root2->right);
    }
    bool isSubTree(Node* T, Node* S) {
        // Your code here
        if(!S) return true;
        if(!T) return false;
        
        if(identical(T,S)){
            return true;
        }
        return isSubTree(T->left,S) or isSubTree(T->right,S);
        
    }
};