//{ Driver Code Starts
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* buildList() {
    vector<int> arr;
    string input;
    getline(cin, input);
    stringstream ss(input);
    int number;
    while (ss >> number) {
        arr.push_back(number);
    }
    if (arr.empty()) {
        return NULL;
    }
    int val = arr[0];
    int size = arr.size();

    Node* head = new Node(val);
    Node* tail = head;

    for (int i = 1; i < size; i++) {
        val = arr[i];
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node* n) {
    while (n) {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
    // Function to add two numbers represented by linked list.
    Node* reverse(Node* curr,Node* prev){
        if(curr==NULL){
            return prev;
        }
        Node* future=curr->next;
        curr->next=prev;
        return reverse(future,curr);
    }
    
    Node* addTwoLists(Node* num1, Node* num2) {
        // code here
         num1=reverse(num1,NULL);
         num2=reverse(num2,NULL);
         Node* curr1=num1;
         Node* curr2=num2;
         
         Node* head=new Node(0);
         Node* tail=head;
         int carry=0;
         
         while(curr1 and curr2){
             int sum=curr1->data + curr2->data + carry;
             tail->next=new Node(sum%10);
             tail=tail->next;
             curr1=curr1->next;
             curr2=curr2->next;
             carry=sum/10;
         }
        // agar curr1 main abhi bhi node hai to
        while(curr1){
            int sum=curr1->data+carry;
            tail->next=new Node(sum%10);
            tail=tail->next;
            curr1=curr1->next;
            carry=sum/10;
        }
        
          while(curr2){
            int sum=curr2->data+carry;
            tail->next=new Node(sum%10);
            tail=tail->next;
            curr2=curr2->next;
            carry=sum/10;
        }
        
        while(carry){
            tail->next=new Node(carry%10);
            carry/=10;
        }
         head=reverse(head->next,NULL);
         return head;
    }
    // reverse the both list
    // add the both list
    // reverse the list
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline character after the integer input

    while (t--) {
        Node* num1 = buildList();
        Node* num2 = buildList();
        Solution ob;
        Node* res = ob.addTwoLists(num1, num2);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends