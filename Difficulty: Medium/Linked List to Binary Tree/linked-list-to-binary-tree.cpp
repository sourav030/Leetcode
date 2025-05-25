/*
// Link list Node
struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    TreeNode* linkedListToBinaryTree(Node* head) {
        // code here
        TreeNode* root=new TreeNode(head->data);
        TreeNode* root1=root;
        head=head->next;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty() and head){
            TreeNode* node=q.front();
            q.pop();
            if(head){
                node->left=new TreeNode(head->data);
                 head=head->next;
            }
            if(head){
                node->right=new TreeNode(head->data);
                head=head->next;
            }
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }
        return root1;
    }
};