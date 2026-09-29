/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* left=headA;
        ListNode* right=headB;

        while(left!=right){
            if(left) left=left->next;
            else left=headB;
            if(right) right=right->next;
            else right=headA;
        }
        return left;
    }
};