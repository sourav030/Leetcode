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
        if(!head)
        return prev;
        
        ListNode* next=head->next;
        head->next=prev;
        return reverse(next, head);
    }
    bool isPalindrome(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast and fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* mid=reverse(slow, nullptr);
        while(head and mid){
            if(head->val!=mid->val) return false;
            head=head->next;
            mid=mid->next;
        }
        return true;
    }
};