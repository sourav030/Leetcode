//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }

};

void printList(Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
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
    Node* linklist(Node* root, Node* root1){
        Node* ans=new Node(-1);
        Node* newNode=ans;
        
        while(root and root1){
            if(root->data<root1->data){
                Node* new_node=new Node(root->data);
            newNode->bottom=new_node;
            root=root->bottom;
            newNode=newNode->bottom;
            }
            else{
            Node* new_node=new Node(root1->data);
            newNode->bottom=new_node;
            root1=root1->bottom;
            newNode=newNode->bottom;
            }
          
        }
        while(root){
             Node* new_node=new Node(root->data);
            newNode->bottom=new_node;
            root=root->bottom;
            newNode=newNode->bottom;
        }
        
        while(root1){
            Node* new_node=new Node(root1->data);
            newNode->bottom=new_node;
            root1=root1->bottom;
            newNode=newNode->bottom;
        }
        return ans->bottom;
    }
    Node *flatten(Node *root) {
        // Your code here
        Node* head=root;
        root=root->next;
        while(root){
            head=linklist(root,head);
            root=root->next;
        }
        return head;
        
    }
};



//{ Driver Code Starts.

int main(void) {

    int t;
    cin >> t;
    while (t--) {
        int n, m, flag = 1, flag1 = 1;
        struct Node * temp = NULL;
        struct Node * head = NULL;
        struct Node * pre = NULL;
        struct Node * tempB = NULL;
        struct Node * preB = NULL;
        cin >> n;
        int work[n];
        for (int i = 0; i < n; i++)
            cin >> work[i];
        for (int i = 0; i < n; i++) {
            m = work[i];
            --m;
            int data;
            scanf("%d", &data);
            temp = new Node(data);
            temp->next = NULL;
            temp->bottom = NULL;

            if (flag) {
                head = temp;
                pre = temp;
                flag = 0;
                flag1 = 1;
            }
            else {
                pre->next = temp;
                pre = temp;
                flag1 = 1;
            }
            for (int j = 0; j < m; j++) {

                int temp_data;
                scanf("%d", &temp_data);
                tempB = new Node(temp_data);

                if (flag1) {
                    temp->bottom = tempB;
                    preB = tempB;
                    flag1 = 0;
                }
                else {
                    preB->bottom = tempB;
                    preB = tempB;
                }
            }
        }
        Node *fun = head;
        Node *fun2 = head;

        Solution ob;
        Node* root = ob.flatten(head);
        printList(root);
        cout << endl;

    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends