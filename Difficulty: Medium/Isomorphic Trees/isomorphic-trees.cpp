/*Complete the function below
Node is as follows:
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    // Return True if the given trees are isomotphic. Else return False.
    bool solve(Node* root1, Node* root2){
        if(!root1 and !root2) return true;
        if(!root1 or !root2)  return false;
        if(root1->data!=root2->data) return false;
        bool noSwap = solve(root1->left, root2->left) &&
                      solve(root1->right, root2->right);

       
        bool swap = solve(root1->left, root2->right) &&
                    solve(root1->right, root2->left);

        return noSwap || swap;
    }
    bool isIsomorphic(Node *root1, Node *root2) {
        // add code here.
        return solve(root1,root2);
    }
};