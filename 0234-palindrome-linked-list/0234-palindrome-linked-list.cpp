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
    ListNode* reverse(ListNode* prev, ListNode* curr){
        if(curr==NULL){
            return prev;
        }
        ListNode* newNode=curr->next;
        curr->next=prev;
       return reverse(curr,newNode);
    }
    bool isPalindrome(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL and fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* tem=head;
        ListNode* reverseNode=reverse(NULL,slow);
        while(reverseNode){
            if(reverseNode->val!=tem->val){
                return 0;
            }
            reverseNode = reverseNode->next;
        tem = tem->next;
        }

        return 1;
    }
};