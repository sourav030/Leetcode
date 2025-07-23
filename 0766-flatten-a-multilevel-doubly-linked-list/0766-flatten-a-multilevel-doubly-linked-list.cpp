/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* solve(Node* curr){
        while(curr->next){
            curr=curr->next;
        }
        return curr;
    }
    Node* flatten(Node* head) {
        Node* curr=head;
        while(curr){
            if(curr->child){
                Node* nextNode=curr->next;
                Node* childNode=curr->child;
                Node* tail=solve(curr->child);
                tail->next = nextNode;
                if (nextNode) {
                    nextNode->prev = tail;
                }
                curr->next = childNode;
                childNode->prev = curr;
                curr->child = nullptr;

            }
            curr=curr->next;
        }
        return head;
    }
};