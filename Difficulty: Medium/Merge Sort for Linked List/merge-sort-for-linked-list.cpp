//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node *node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends

/*
The structure of linked list is the following

struct Node {
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    // Function to sort the given linked list using Merge Sort.
     Node* split(Node *head) {
        Node* fast = head;
        Node* slow = head;
        Node* prev = nullptr;

        // Move fast by 2 steps and slow by 1 step
        while(fast && fast->next) {
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }

        // Split the list by making prev->next = nullptr
        if (prev) {
            prev->next = nullptr;
        }

        return slow;  // Return the second half of the list
    }
    Node* merge(Node* head,Node* head1){
        Node* tem2=new Node(-1);
        Node* tem=tem2;
        while(head and head1){
            if(head->data<head1->data){
                tem->next=head;
                head=head->next;
            }
            else{
                tem->next=head1;
                head1=head1->next;
            }
            tem=tem->next;
        }
        while(head){
            tem->next=head;
            head=head->next;
            tem=tem->next;
        }
        while(head1){
            tem->next=head1;
            head1=head1->next;
            tem=tem->next;
        }
        return tem2->next;
    }
    Node* mergeSort(Node* head) {
        // your code here
        if(!head or !head->next) return head;
        
        Node* head1=split(head);
        head=mergeSort(head);
        head1=mergeSort(head1);
        return merge(head,head1);
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

        // Read numbers from the input line
        while (ss >> number) {
            arr.push_back(number);
        }
        Node *head = nullptr;
        // Check if the array is empty
        if (!arr.empty()) {
            head = new Node(arr[0]);
            Node *tail = head;
            for (size_t i = 1; i < arr.size(); ++i) {
                tail->next = new Node(arr[i]);
                tail = tail->next;
            }
        }
        Solution obj;
        Node *ans = obj.mergeSort(head);
        printList(ans);
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends