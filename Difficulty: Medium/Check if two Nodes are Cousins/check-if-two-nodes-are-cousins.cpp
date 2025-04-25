//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node* root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends

/*Complete the function below
Node is as follows:
struct Node {
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
    // Function to check if two nodes are cousins in a tree
   vector<pair<int, pair<int, int>>> arr; // node, {level, parent}

void solve(Node* root, int parent, int level) {
    if (!root) return;
    
    arr.push_back({root->data, {level, parent}});
    
    solve(root->left, root->data, level + 1);
    solve(root->right, root->data, level + 1);
}

bool isCousins(Node* root, int x, int y) {
    arr.clear(); 
    
    solve(root, -1, 0); 
    
    int levelX = -1, levelY = -1;
    int parentX = -1, parentY = -1;
    
    for (auto ele : arr) {
        int node = ele.first;
        int level = ele.second.first;
        int parent = ele.second.second;
        
        if (node == x) {
            levelX = level;
            parentX = parent;
        }
        if (node == y) {
            levelY = level;
            parentY = parent;
        }
    }
    
    return (levelX == levelY && parentX != parentY);
}

};


//{ Driver Code Starts.

int main() {

    int t;
    scanf("%d ", &t);
    Solution solution;
    while (t--) {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);
        int x, y;
        scanf("%d ", &x);
        scanf("%d ", &y);
        cout << solution.isCousins(root, x, y) << endl;
        cout << "~" << endl;
    }
    return 1;
}
// } Driver Code Ends