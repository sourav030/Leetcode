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
    ListNode* partition(ListNode* head, int x) {
        ListNode* before=new ListNode(-1);
        ListNode* tailbefore=before;
        ListNode* after=new ListNode(-1);
        ListNode* tailafter=after;

        while(head){
            if(head->val<x){
                tailbefore->next=head;
                tailbefore=tailbefore->next;
            }
            else{
                tailafter->next=head;
                tailafter=tailafter->next;
            }
            head=head->next;
        }
        
       tailafter->next = nullptr; // Important: avoid cycle
        tailbefore->next = after->next;

        return before->next;
       
        return before;
    }
};