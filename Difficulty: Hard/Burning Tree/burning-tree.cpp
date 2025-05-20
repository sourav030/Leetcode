/*
class Node {
  public:
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
      
    int findDepth(Node* root) {
    if (root == nullptr) return 0;
    
    int left = findDepth(root->left);
    int right = findDepth(root->right);
    
    return max(left, right) + 1;
}

int findTarNode(Node* root, int target, int &ans) {
    if (root == nullptr)
        return -1;
    
    if (root->data == target) {
        int depth = findDepth(root) - 1;
        ans = max(ans, depth);
        return 1;
    }
    
    int left = findTarNode(root->left, target, ans);
    if (left != -1) {
        int depth = findDepth(root->right);
        ans = max(ans, left + depth);
        return left + 1;
    }
    
    int right = findTarNode(root->right, target, ans);
    if (right != -1) {
        int depth = findDepth(root->left);
        ans = max(ans, right + depth);
        return right + 1;
    }
    
    return -1;
}

int minTime(Node *root, int target) {
    int ans = 0;
    findTarNode(root, target, ans);
    return ans;
}

};