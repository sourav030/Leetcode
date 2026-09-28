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
    int size(ListNode* head){
        int count =0;
        while(head){
            head=head->next;
            count++;
        }
        return count;
    }
    ListNode* removeNthFromEnd(ListNode* head, int k) {
      
        int n=size(head);
        int deleteNode=n-k+1;
     
        ListNode* prev=nullptr;
        ListNode* ans=head;
        if(deleteNode==1) return head->next;
        while(deleteNode>1){
            prev=head;
            head=head->next;
            deleteNode--;
        }
     
        if(prev and head){
            prev->next=head->next;
        }
        return ans;
    }
};