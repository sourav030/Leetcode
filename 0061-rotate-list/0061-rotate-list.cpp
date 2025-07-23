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
public:
    int length(ListNode* head){
       
        int count=0;
        while(head){
            count++;
            head=head->next;
        }
        return count;
    }
    ListNode* rotateRight(ListNode* head, int k) {
         if(!head or !head->next){
            return head;
        }
        int len=length(head);
        int a=k%len;
        if(a==0){
            return head;
        }
        int count=len-a;
        ListNode* prev=nullptr;
        ListNode* curr=head;
        while(count--){
            prev=curr;
            curr=curr->next;
        }
        prev->next=nullptr;
        ListNode* tail=curr;
        while(tail and tail->next){
            tail=tail->next;
        }
        tail->next=head;
        return curr;

    }
};