//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    struct Node *bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

void printList(Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
    printf("\n");
}


// } Driver Code Ends
/* Node structure  used in the program

struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }

};
*/

class Solution {
  public:
    // Function which returns the  root of the flattened linked list.
    
    Node* merge(Node* head1, Node* head2){
        Node* head=new Node(-1);
        Node* tail=head;
        while(head1 and head2){
            if(head1->data<=head2->data){
                tail->bottom=head1;
                head1=head1->bottom;
                tail=tail->bottom;
                tail->bottom=NULL;
            }
            else{
                tail->bottom=head2;
                head2=head2->bottom;
                tail=tail->bottom;
                tail->bottom=NULL;
            }
        }
        
        if(head1){
            tail->bottom=head1;
        }
        if(head2){
            tail->bottom=head2;
        }
        return head->bottom;
    }
    
    Node *flatten(Node *root) {
        // Your code here
        Node *head1, *head2, *head3;
        while(root->next){
            head1=root;
            head2=root->next;
            head3=root->next->next;
            head1->next=NULL;
            head2->next=NULL;
            
           root= merge(head1,head2);
           root->next=head3;
            
        }
        return root;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        vector<int> work;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            work.push_back(number);
        }
        n = work.size();

        Node *head = NULL;
        Node *pre = NULL;

        for (int i = 0; i < n; i++) {
            int m = work[i] - 1;
            int data;
            cin >> data;
            Node *temp = new Node(data);
            if (head == NULL) {
                head = temp;
                pre = temp;
            } else {
                pre->next = temp;
                pre = temp;
            }

            Node *preB = temp;
            for (int j = 0; j < m; j++) {
                int temp_data;
                cin >> temp_data;
                Node *tempB = new Node(temp_data);
                preB->bottom = tempB;
                preB = tempB;
            }
        }

        Solution ob;
        Node *root = ob.flatten(head);
        printList(root);
    }
    return 0;
}

// } Driver Code Ends