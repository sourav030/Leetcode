/* node structure  used in the program

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

class Solution {
  public:
    // Function to construct binary tree from parent array.
    Node *createTree(vector<int> parent) {
        // Your code here
         int n= parent.size();
        vector<Node*> nodes(n, nullptr);

        // Create all nodes
        for (int i = 0; i < n; i++) {
            nodes[i] = new Node(i);
        }

        Node* root = nullptr;

        for (int i = 0; i < n; i++) {
            if (parent[i] == -1) {
                root = nodes[i];  // root found
            } else {
                Node* par = nodes[parent[i]];
                if (par->left == nullptr)
                    par->left = nodes[i];
                else
                    par->right = nodes[i];
            }
        }

        return root;
        
    }
};