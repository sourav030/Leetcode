//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Definition of the Node class
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
};

// Function to print the tree in postorder traversal
void printPostOrder(Node *root) {
    if (root == NULL)
        return;
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->data << " ";
}


// } Driver Code Ends
// Class that contains the logic to build the binary tree
/*
Definition of the Node class
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
};
*/
class Solution {
  public:
    unordered_map<int,int> mp;

Node* solve(vector<int>& preorder, int start, int end, int& preIndex) {
    // Base condition
    if (end < start) return NULL;

    Node* root = new Node(preorder[preIndex]);
    preIndex++;  // Move to the next index in preorder

    // Find the index of the root in the inorder array
    int value = mp[root->data];

    // Recursively build the left and right subtrees
    root->left = solve(preorder, start, value - 1, preIndex);
    root->right = solve(preorder, value + 1, end, preIndex);

    return root;
}

// Function to build the tree from given inorder and preorder traversals
Node* buildTree(vector<int>& inorder, vector<int>& preorder) {
    // Map inorder values to their indices
    for (int i = 0; i < inorder.size(); i++) {
        mp[inorder[i]] = i;
    }

    int preIndex = 0;  // Initialize the preorder index
    return solve(preorder, 0, inorder.size() - 1, preIndex);  // Return the constructed tree
}

};

//{ Driver Code Starts.

// Main function where the test cases are handled
int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> inorder, preorder;

        // Input the inorder traversal
        string input;
        getline(cin, input);
        stringstream ss1(input);
        int num;
        while (ss1 >> num)
            inorder.push_back(num);

        // Input the preorder traversal
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> num)
            preorder.push_back(num);

        // Create Solution object and build the tree
        Solution obj;
        Node *root = obj.buildTree(inorder, preorder);

        // Print the postorder traversal of the constructed tree
        printPostOrder(root);
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends