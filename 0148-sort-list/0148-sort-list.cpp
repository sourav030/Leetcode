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
    ListNode* middle(ListNode* head){
    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* prev = nullptr;

    while(fast && fast->next){
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    return prev; 
}

    ListNode* merge(ListNode* head1 , ListNode* head2){
        if (!head1) return head2;
        if (!head2) return head1;

        ListNode* ans=new ListNode(-1);
        ListNode* tail=ans;

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

        while(head1){
             tail->next=head1;
             head1=head1->next;
            tail=tail->next;
        }

        while(head2){
            tail->next=head2;
            head2=head2->next;
            tail=tail->next;
        }
        return ans->next;
    }
    ListNode* sortList(ListNode* head) {
        if(!head or !head->next){
            return head;
        }
        ListNode* mid=middle(head);
        ListNode* left=head;
        ListNode* right=mid->next;
        mid->next=nullptr;

        left=sortList(left);
        right=sortList(right);
        
        ListNode* result=merge(left,right);
        return result;
        
    }
};