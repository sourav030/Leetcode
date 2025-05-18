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
    int Length(ListNode* head){
        int count=0;
        while(head){
            count++;
            head=head->next;
        }
        return count;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int headAlen=Length(headA);
        int headBlen=Length(headB);
        if(headAlen>headBlen){
            int a=headAlen-headBlen;
            while(a--){
                headA=headA->next;
            }
        }
        else if(headBlen>headAlen){
            int a=headBlen-headAlen;
            while(a--){
                headB=headB->next;
            }
        }
        while(headA!=headB){
            headA=headA->next;
            headB=headB->next;
        }
        return headA;

    }
};