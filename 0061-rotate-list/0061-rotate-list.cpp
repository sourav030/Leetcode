/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    int size(ListNode* head){
        int x=0;
        ListNode* cur=head;
        while(cur){
            x++;
            cur=cur->next;
        }
        return x;
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL or head->next==NULL){
            return head;
        }
        if(k==0) return head;
        int x=size(head);
        ListNode* curr=head;
        ListNode* prev=NULL;
        k=k%x;
        if(k==0){
            return head;
        }
        x-=k;
        while(x--){
            prev=curr;
            curr=curr->next;
        }
        prev->next=NULL;
        ListNode* Tail=curr;
        while(Tail->next!=NULL){
            Tail=Tail->next;
        }
        Tail->next=head;
        head=curr;
        return head;
    }
};