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
    ListNode* merge(ListNode* head1,ListNode* head2){
        if(!head1) return head2;
        if(!head2) return head1;
        ListNode* head3=new ListNode(-1);
        ListNode* tail=head3;
        while(head1 and head2){
            if(head1->val<head2->val){
                tail->next=head1;
                head1=head1->next;
            }
            else{
                tail->next=head2;
                head2=head2->next;
            }
            tail=tail->next;
        }
        if(head1){
            tail->next=head1;
        }
        if(head2){
            tail->next=head2;
        }
        return head3->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head=nullptr;
        for(int i=0; i<lists.size(); i++){
            head=merge(head,lists[i]);
        }
        return head;
    }
};