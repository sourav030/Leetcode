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
    ListNode* solve(ListNode* head){
        ListNode* fast=head;
        ListNode* slow=head;
        ListNode* prev=nullptr;
        while(fast and fast->next){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        prev->next=nullptr;
        return slow;
    }
    ListNode* reverse(ListNode* prev,ListNode* curr){
        if(!curr){
            return prev;
        }
        ListNode* next=curr->next;
        curr->next=prev;
        return reverse(curr,next);
    }
    void reorderList(ListNode* head) {
        if(!head or !head->next) return ;
        ListNode* mid=solve(head);
        ListNode* midReverse=reverse(nullptr,mid);
        ListNode* curr=head;
        head=head->next;
        bool chance=true;
        while(head and midReverse){
                if(chance){
                    curr->next=midReverse;
                    midReverse=midReverse->next;
                }
                else{
                    curr->next=head;
                    head=head->next;
                }
                curr=curr->next;
                chance=!chance;
        }
        while(head){
            curr->next=head;
            head=head->next;
            curr=curr->next;
        }
        while(midReverse){
            curr->next=midReverse;
            midReverse=midReverse->next;
            curr=curr->next;
        }
    }
};