/*struct Node
{
    int data;
    Node *left, *right;
};*/

Node* buildTree(int post[], int low, int high){
    if(low>high){
        return nullptr;
    }
    int mid=low+(high-low)/2;
    Node* root=new Node(post[mid]);
    root->left=buildTree(post, low, mid-1);
    root->right=buildTree(post,mid+1,high);
    return root;
}
Node *constructTree(int post[], int size) {
    // code here
    sort(post,post+size);
    int n=size-1;
    return buildTree(post,0,n);
}