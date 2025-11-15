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
    ListNode* reverseLinkList(ListNode* head, ListNode* prev){
        if(!head){
            return prev;
        }
        ListNode* Next=head->next;
        head->next=prev;
        return reverseLinkList(Next,head);
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1=reverseLinkList(l1, nullptr);
        l2=reverseLinkList(l2,nullptr);
        ListNode* ans=new ListNode(-1);
        ListNode* tail=ans;
        int carry=0;
        while(l1 or l2 or carry){
            int val1=l1?l1->val:0;
            int val2=l2?l2->val:0;
            int sum=val1+val2+carry;
            carry=sum/10;
            tail->next=new ListNode(sum%10);
            tail=tail->next;
            if(l1)
            l1=l1->next;
            if(l2)
            l2=l2->next;
        }
        ans=reverseLinkList(ans->next,nullptr);
        
        return ans;
    }
};