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
        int carry=0;
        ListNode* ans=new ListNode(-1);
        ListNode* tail=ans;
        while(l1 or l2 or carry){
            int a=l1? l1->val:0;
            int b=l2? l2->val:0;
            int sum=a+b+carry;
            carry=sum/10;
            ListNode* new_node= new ListNode(sum%10);
            tail->next=new_node;
            tail=new_node;

           if(l1) l1=l1->next;
           if(l2) l2=l2->next;
        }
        return ans->next;
    }
};