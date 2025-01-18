//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data % 10;
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends
// User function template for C++

/*

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
   Node* reverse(Node* prev, Node* curr) {
    if (curr == NULL) {
        return prev;
    }
    Node* nextNode = curr->next;
    curr->next = prev;
    return reverse(curr, nextNode);
}

Node* addOne(Node* head) {
    Node* revHead = reverse(NULL, head);
    Node* curr = revHead;
    int carry = 1;

    while (curr) {
        int val = curr->data + carry;
        curr->data = val % 10;
        carry = val / 10;

        if (carry == 0) {
            break;
        }

        if (curr->next == NULL && carry > 0) {
            Node* newNode = new Node(carry);
            newNode->data = carry;
            newNode->next = NULL;
            curr->next = newNode;
            break;
        }

        curr = curr->next;
    }

    return reverse(NULL, revHead);
}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        struct Node* head = new Node(data);
        struct Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head);
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends