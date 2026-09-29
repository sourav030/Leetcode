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
        int count=0;
        while(head){
            head=head->next;
            count++;
        }
        return count;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len=size(head);
        int k=len-n+1;
        if(k==1) return head->next;
        ListNode* start=head;
        ListNode* prev=nullptr;
        for(int i=0; i<k-1; i++){
            prev=start;
            start=start->next;
        }
        if(prev and start){
            prev->next=start->next;
            cout<<start->val;
        }
        return head;
    }
};