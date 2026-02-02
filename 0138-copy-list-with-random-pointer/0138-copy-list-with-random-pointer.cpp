/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*>mp;
        Node* head1=new Node(-1);
        Node* tail=head1;
        Node* temp=head;
        while(temp){
            tail->next=new Node(temp->val);
            tail=tail->next;
            mp[temp]=tail;
            temp=temp->next;
        }   
        tail=head1->next;
        while(head){
            Node* RandHead=mp[head->random];
            tail->random=RandHead;
            tail=tail->next;
            head=head->next;
        }
        return head1->next;
    }
};