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
    int ans=0;
    int leve=-1;
    void solve(Node* root, int level, int sum){
        if(!root) return;
        level++;
        sum+=root->data;
        if(!root->left and !root->right){
            if(level>leve){
                leve=level;
                ans=sum;
            }
            if(level==leve){
                ans=max(ans,sum);
            }
            return;
        }
        solve(root->left,level,sum);
        solve(root->right,level,sum);
    }
    int sumOfLongRootToLeafPath(Node *root) {
        // code here
        solve(root,0,0);
        return ans;
    }
};