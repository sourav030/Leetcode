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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* head1=new ListNode(-1);
        ListNode* tail1=head1;
        ListNode* head2=new ListNode(-1);
        ListNode* tail2=head2;

        bool odd=true;
        while(head){
            if(odd){
                tail1->next=head;
                head=head->next;
                tail1=tail1->next;
                tail1->next=nullptr;
            }
            else{
                tail2->next=head;
                head=head->next;
                tail2=tail2->next;
                tail2->next=nullptr;
            }
            odd=!odd;
        }
        tail1->next=head2->next;
        return head1->next;
    }
};