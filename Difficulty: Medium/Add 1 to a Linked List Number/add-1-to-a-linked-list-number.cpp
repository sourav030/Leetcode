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
   Node* reverse(Node* head, Node* prev){
       if(!head) return prev;
       Node* Next=head->next;
       head->next=prev;
       return reverse(Next,head);
   }
    Node* addOne(Node* head) {
        // Your Code here
         head=reverse(head,nullptr);
         Node* curr=head;
         int carry=0;
         int val=curr->data;
         val=val+1;
         carry=val/10;
         val=val%10;
         curr->data=val;
         curr=curr->next;
         while(curr and carry){
             int sum=curr->data+carry;
              val=sum%10;
             carry=sum/10;
             curr->data=val;
             curr=curr->next;
         }
         head=reverse(head,nullptr);
         if(carry and !curr){
             Node* newNode=new Node(carry);
             newNode->next=head;
             head=newNode;
         }
         return head;
        // return head of list after adding one
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