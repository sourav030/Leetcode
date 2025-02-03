//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node() {
        data = 0;
        left = right = NULL;
    }

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};


// } Driver Code Ends
/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

class Solution {
  public:
    // Function to return the lowest common ancestor in a Binary Tree.
    bool solve(vector<Node*> &path, Node* root , int n1){
        if(!root){
            return 0;
        }
        path.push_back(root);
        if(root->data==n1){
            return 1;
        }
        if(solve(path,root->left ,n1) or solve(path,root->right,n1)){
            return 1;
        }
        path.pop_back();
        return 0;
    }
    Node* lca(Node* root, int n1, int n2) {
        // Your code here
        vector<Node*>path1;
        vector<Node*>path2;
        if(!solve(path1,root,n1) or !solve(path2,root,n2)){
            return NULL;
        }
        
        int i;
        for( i=0; i<path1.size() and i<path2.size(); i++){
            if(path1[i]!=path2[i]){
                break;
            }
        }
        return path1[i-1];
    }
};

//{ Driver Code Starts.

Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case: If the string is empty or the root is 'N'
    if (str.length() == 0 || str[0] == 'N') {
        return NULL;
    }

    // Create a vector from the input string
    vector<string> ip;
    istringstream iss(str);
    for (string val; iss >> val;) {
        ip.push_back(val);
    }

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Initialize a queue to level-order build the tree
    queue<Node*> q;
    q.push(root);

    int i = 1; // Start from the second element
    while (!q.empty() && i < ip.size()) {
        Node* currNode = q.front();
        q.pop();

        // Process the left child
        if (i < ip.size() && ip[i] != "N") {
            currNode->left = newNode(stoi(ip[i]));
            q.push(currNode->left);
        }
        i++;

        // Process the right child
        if (i < ip.size() && ip[i] != "N") {
            currNode->right = newNode(stoi(ip[i]));
            q.push(currNode->right);
        }
        i++;
    }
    return root;
}

// Function for Inorder Traversal
void printInorder(Node* root) {
    if (!root) {
        return;
    }

    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

int main() {
    int t;
    cin >> t;
    cin.ignore(); // This will consume the newline character left after reading t

    while (t--) {
        string s;
        getline(cin, s); // Read the tree string

        int a, b;
        cin >> a >> b; // Read the two integer values for LCA search
        cin.ignore();  // Consume the newline character after reading integers

        Node* root = buildTree(s);
        Solution ob;
        Node* ans = ob.lca(root, a, b);

        if (ans != NULL) {
            cout << ans->data << endl;
        } else {
            cout << "No common ancestor found\n";
        }

        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends