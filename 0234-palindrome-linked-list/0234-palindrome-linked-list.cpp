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
    ListNode* reverse(ListNode* head, ListNode* prev){
        if(!head){
            return prev;
        }
        ListNode* Next=head->next;
        head->next=prev;
        return reverse(Next,head);
    }
    bool isPalindrome(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast and fast->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        ListNode* head1=reverse(slow,nullptr);
        while(head1 and head){
            if(head1->val!=head->val){
                return false;
            }
            head1=head1->next;
            head=head->next;
        }
        return true;
    }
};