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
        if(!head) return prev;
        ListNode* Next=head->next;
        head->next=prev;
        return reverse(Next,head);
    }
    bool isPalindrome(ListNode* head) {
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast and fast->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        ListNode* revNode=reverse(slow,nullptr);
        ListNode* tem=head;
        while(revNode){
            if(revNode->val!=tem->val){
                return false;
            }
            revNode=revNode->next;
            tem=tem->next;
        }
        return true;
    }
};