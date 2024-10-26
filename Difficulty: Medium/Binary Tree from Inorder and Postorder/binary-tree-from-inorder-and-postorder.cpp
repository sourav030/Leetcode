//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL)
        return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}


// } Driver Code Ends
/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

class Solution {
  public:
    
    int find(vector<int>inorder, int start, int end, int target){
        for(int i=start; i<=end; i++){
            if(target==inorder[i]) return i;
        }
        return -1;
    }
    
    Node* Tree(vector<int> inorder, vector<int> postorder, int start,int end,int index){
        while(start>end) return NULL;
        Node* root=new Node(postorder[index]);
        
        int pos=find(inorder, start, end,postorder[index]);
        
        root->right=Tree(inorder, postorder,pos+1,end,index-1);
        root->left=Tree(inorder,postorder,start,pos-1,index-(end-pos)-1);
        return root;
    }
    // Function to return a tree created from postorder and inoreder traversals.
    Node* buildTree(vector<int> inorder, vector<int> postorder) {
        // code here-1
        int start=0;
        int n=inorder.size()-1;
        return Tree(inorder,postorder,start,n,n);
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);

        stringstream ss(input);
        vector<int> inorder;
        int number;
        while (ss >> number) {
            inorder.push_back(number);
        }

        getline(cin, input);
        stringstream ss2(input);
        vector<int> postorder;
        while (ss2 >> number) {
            postorder.push_back(number);
        }
        Solution obj;
        Node* root = obj.buildTree(inorder, postorder);
        preOrder(root);
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends