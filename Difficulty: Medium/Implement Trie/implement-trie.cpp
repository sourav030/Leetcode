//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++
class TrieNode {
public:
    unordered_map<char, TrieNode*> children;  // map to store child nodes
    bool isEndOfWord;  // true if the node represents the end of a word

    TrieNode() {
        isEndOfWord = false;
    }
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();  // Initialize the root node
    }

    // Insert a word into the Trie
    void insert(string &word) {
        TrieNode* node = root;
        for (char c : word) {
            // If the character doesn't exist, create a new node
            if (node->children.find(c) == node->children.end()) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];  // Move to the child node
        }
        node->isEndOfWord = true;  // Mark the end of the word
    }

    // Search for a word in the Trie
    bool search(string &word) {
        TrieNode* node = root;
        for (char c : word) {
            if (node->children.find(c) == node->children.end()) {
                return false;  // Word not found
            }
            node = node->children[c];
        }
        return node->isEndOfWord;  // Check if it's the end of a valid word
    }

    // Check if a prefix exists in the Trie
    bool isPrefix(string &word) {
        TrieNode* node = root;
        for (char c : word) {
            if (node->children.find(c) == node->children.end()) {
                return false;  // Prefix not found
            }
            node = node->children[c];
        }
        return true;  // Prefix exists
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int q;
        cin >> q;
        cin.ignore();
        vector<bool> ans;
        Trie ob;
        for (int i = 0; i < q; i++) {
            int x;
            cin >> x;
            string s;
            cin >> s;
            cin.ignore();
            if (x == 1) {
                ob.insert(s);
            } else if (x == 2) {
                ans.push_back(ob.search(s));
            } else if (x == 3) {
                ans.push_back(ob.isPrefix(s));
            }
        }
        cout << boolalpha;
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends