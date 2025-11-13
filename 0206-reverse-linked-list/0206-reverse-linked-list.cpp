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
    ListNode* reverse(ListNode* curr, ListNode* prev){
        if(!curr){
            return prev;
        }
        ListNode* Next=curr->next;
        curr->next=prev;
        return reverse(Next,curr);
    }
    ListNode* reverseList(ListNode* head) {
        return reverse(head, nullptr);
    }
};