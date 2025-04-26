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

    // Function to return a tree created from postorder and inoreder traversals.
    unordered_map<int,int>mp;
    
    Node* solve(vector<int>&postorder, int start,int end, int &index){
        if(start>end or index<0) return nullptr;
        int rootValue=postorder[index--];
        Node* root=new Node(rootValue);
        int mid=mp[rootValue];
        root->right=solve(postorder,mid+1,end,index);
        root->left=solve(postorder,start,mid-1,index);
        return root;
    }
    Node* buildTree(vector<int> inorder, vector<int> postorder) {
        // code here
        mp.clear();
        for(int i=0; i<inorder.size(); i++){
            mp[inorder[i]]=i;
        }
        int start=0;
        int end=inorder.size()-1;
        int index=postorder.size()-1;
        return solve(postorder,start,end,index);
        
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