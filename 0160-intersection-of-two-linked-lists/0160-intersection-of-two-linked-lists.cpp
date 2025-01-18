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
        int lenA=0;
        int lenB=0;
        ListNode* tem=headA;
        ListNode* temB=headB;
        while(tem){
            lenA++;
            tem=tem->next;
        }
        while(temB){
            lenB++;
            temB=temB->next;
        }
        if(lenA>lenB){
            int count=lenA-lenB;
            while(count){
                headA=headA->next;
                count--;
            }
        }
        else{
            int count=lenB-lenA;
            while(count){
                headB=headB->next;
                count--;
            }
        }
        while(headA!=headB){
            headA=headA->next;
            headB=headB->next;
        }
        return headA;
    }
};