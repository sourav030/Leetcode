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
        int len=0;
        while(head){
            len++;
            head=head->next;
        }
        return len;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len=length(head);
        int index=len-n;
        ListNode *orignal=head;
        if(index==0){
            return head->next;
        }
        while(index!=1 and head){
            head=head->next;
            index--;
        }
        if(head){
            head->next=head->next->next;
        }
       
        return orignal;
    }
};