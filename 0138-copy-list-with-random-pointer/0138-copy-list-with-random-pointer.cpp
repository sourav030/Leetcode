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
        Node* curr=head;
        unordered_map<Node*, Node*>mp;
        Node* ans=new Node(-1);
        Node* tail=ans;
        while(curr){
            tail->next=new Node(curr->val);
            tail=tail->next;
            mp[curr]=tail;
           
            curr=curr->next;
        }
        curr=head;
        while(curr){
            Node* myNode=mp[curr];
            Node* random=mp[curr->random];
            myNode->random=random;
            curr=curr->next;
        }
        return ans->next;
    }
};