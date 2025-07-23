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
        ListNode* curr=new ListNode(-1);
        ListNode* tail=curr;
        ListNode* curr2=new ListNode(-1);
        ListNode* tail2=curr2;
        bool odd=true;
        while(head){
            if(odd){
                tail->next=head;
                tail=tail->next;
            }
            else{
                tail2->next=head;
                tail2=tail2->next;
            }
            head=head->next;
            odd=!odd;
        }
        tail2->next = nullptr;
        curr=curr->next;
        tail->next=curr2->next;
        return curr;
    }
};