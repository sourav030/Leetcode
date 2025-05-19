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
    ListNode* reverse(ListNode* curr,ListNode* end){
        ListNode* prev=nullptr;
        ListNode* start=curr;
        while(start!=end){
            ListNode* Next=start->next;
            start->next=prev;
            prev=start;
            start=Next;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int count=0;
        ListNode* tem=head;
        while(tem and count<k){
            tem=tem->next;
            count++;
        }
        if(count<k) return head;
        ListNode* new_head=reverse(head,tem);
        head->next=reverseKGroup(tem,k);
        return new_head;
    }
};