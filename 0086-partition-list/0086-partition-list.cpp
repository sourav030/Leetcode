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
    ListNode* partition(ListNode* head, int x) {

        ListNode* head1=new ListNode(-1);
        ListNode* head2=new ListNode(-1);
        ListNode* left=head1;
        ListNode* right=head2;
        while(head){
            if(head->val<x){
                left->next=head;
                left=left->next;
            }
            else{
                right->next=head;
                right=right->next;
            }
            head=head->next;
        }
        left->next=nullptr;
        right->next=nullptr;
        left->next=head2->next;
        return head1->next;
    }
};