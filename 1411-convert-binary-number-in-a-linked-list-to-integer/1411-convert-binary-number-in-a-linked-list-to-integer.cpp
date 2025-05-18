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
    ListNode* Reverse(ListNode* head,ListNode* prev){
        if(!head) return prev;
        ListNode* Next=head->next;
        head->next=prev;
        return Reverse(Next,head);
    }
    int getDecimalValue(ListNode* head) {
        int sum=0;
        int i=0;
        head=Reverse(head,nullptr);
        while(head){
            int val=head->val*pow(2,i);
            sum+=val;
            i++;
            head=head->next;
        }
        return sum;
    }
};