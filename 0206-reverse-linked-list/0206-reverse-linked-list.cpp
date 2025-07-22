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
    ListNode* solve(ListNode* prev,ListNode* head){
        if(!head){
            return prev;
        }
        ListNode* Next=head->next;
        head->next=prev;
        return solve(head,Next);
    }
    ListNode* reverseList(ListNode* head) {
        return solve(nullptr,head);
    }
};