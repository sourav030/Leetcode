/*The Node structure is
class Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};*/

class Solution {
  public:
    bool isDeadEndUtil(Node* root, int minVal, int maxVal) {
        if (!root) return false;
        
        // If at leaf node and minVal == maxVal, dead end found
        if (!root->left && !root->right) {
            if (minVal == maxVal) return true;
            else return false;
        }
        
        // Check left and right subtree with updated ranges
        bool leftDeadEnd = isDeadEndUtil(root->left, minVal, root->data - 1);
        bool rightDeadEnd = isDeadEndUtil(root->right, root->data + 1, maxVal);
        
        return leftDeadEnd || rightDeadEnd;
    }
    
    bool isDeadEnd(Node *root) {
        // BST contains positive integers only (min starts from 1)
        return isDeadEndUtil(root, 1, INT_MAX);
    }
};
