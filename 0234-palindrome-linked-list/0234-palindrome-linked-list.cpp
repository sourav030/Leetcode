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
    ListNode* MiddleNode(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast and fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* reverse(ListNode* prev,ListNode* head){
        if(!head){
            return prev;
        }
        ListNode* Next=head->next;
        head->next=prev;
        return reverse(head,Next);
    }
    bool isPalindrome(ListNode* head) {
        ListNode* mid=MiddleNode(head);
        ListNode* RevMid=reverse(nullptr,mid);
        while(RevMid and head){
            if(RevMid->val!=head->val){
                return false;
            }
            RevMid=RevMid->next;
            head=head->next;
        }
        return true;
    }
};