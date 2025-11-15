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
        Node* tail=head;
        Node* ans=new Node(-1);
        Node* tail1=ans;
        unordered_map<Node*, Node*>mp;
        while(tail){
            tail1->next=new Node(tail->val);
            tail1=tail1->next;
            mp[tail]=tail1;
            tail=tail->next;
        }
        while(head){
            Node* dupNode=mp[head];
            Node* duplicRandom=mp[head->random];
            dupNode->random=duplicRandom;
            head=head->next;
        }
        return ans->next;
    }
};