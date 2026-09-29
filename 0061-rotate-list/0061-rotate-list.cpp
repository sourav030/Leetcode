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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* tail=head;
        int len=size(head);
        if(len==0){
            return nullptr;
        }
        k=k%len;
        if(k==0 or !head or !head->next){
            return head;
        }

        int rotate=len-k;
        for(int i=0; i<rotate-1; i++){
            tail=tail->next;
        }
        ListNode * ans=tail->next;
        ListNode* tail2=ans;
        tail->next= nullptr;
        while(tail2->next){
            tail2=tail2->next;
        }
        tail2->next=head;
        return ans;
    }
};