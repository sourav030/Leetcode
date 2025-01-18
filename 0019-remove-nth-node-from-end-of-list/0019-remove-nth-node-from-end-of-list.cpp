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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL) return NULL;
        int count=0;
        ListNode* temp=head;
        while(temp){
            temp=temp->next;
            count++;
        }
        if(count==1) return NULL;
        if(n==count) return head->next;
        ListNode* temp2=head;
        int a=1;
        while(a<count-n){
            temp2=temp2->next;
            a++;
        }
       
        if(temp2->next!=NULL and temp2!=NULL)
        temp2->next=temp2->next->next;
        return head;

    }
};