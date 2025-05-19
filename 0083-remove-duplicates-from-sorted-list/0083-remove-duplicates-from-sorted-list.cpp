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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return head;
        ListNode* prev=head;
        ListNode* start=head->next;
        while(start){
            if(start->val!=prev->val){
                prev->next=start;
                prev=prev->next;
            }
            start=start->next;
        }
        prev->next = nullptr;
        return head;
    }
};