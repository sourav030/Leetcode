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
        if(!head) return nullptr;
        Node* head1=new Node(head->val);
        unordered_map<Node*,Node*>mp;
        Node* tail2=head1;
        Node* tail1=head;

        while(tail1){
            mp[tail1]=tail2;
            tail1=tail1->next;
            if(tail1){

            Node* new_node=new Node(tail1->val);
            tail2->next=new_node;
            tail2=tail2->next;
            }
        }

        tail1=head;
        tail2=head1;

        while(tail1){
            tail2->random=mp[tail1->random];
            tail2=tail2->next;
            tail1=tail1->next;
        }
        return head1;

    }
};