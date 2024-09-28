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
       ListNode* head=new ListNode(0);
       ListNode* tail=head;
       int carry=0;
       while(l1 and l2){
        int sum=l1->val+l2->val+carry;
        ListNode* tem=new ListNode(sum%10);
        tail->next=tem;
        carry=sum/10;
        tail=tail->next;
        l1=l1->next;
        l2=l2->next;
       }
       while(l1){
        int sum=l1->val+carry;
        ListNode* tem=new ListNode(sum%10);
        tail->next=tem;
        carry=sum/10;
        tail=tail->next;
        l1=l1->next;
       }
       while(l2){
       int sum=l2->val+carry;
        ListNode* tem=new ListNode(sum%10);
        tail->next=tem;
        carry=sum/10;
        l2=l2->next;
        tail=tail->next;
       }
       while(carry){
        ListNode* tem=new ListNode(carry%10);
        tail->next=tem;
        carry/=10;
       }
       return head->next;
    }
};