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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans=new ListNode(-1);
        ListNode* tail=ans;
        int carry=0;
        while(l1 or l2 or carry){
            int val=l1?l1->val:0;
            int val2=l2?l2->val:0;
            int sum=val+val2+carry;
            carry=sum/10;
            sum=sum%10;
            tail->next=new ListNode(sum);
            tail=tail->next;
            if(l1){
                l1=l1->next;
            }
            if(l2){
                l2=l2->next;
            }
        }
        return ans->next;
    }
};