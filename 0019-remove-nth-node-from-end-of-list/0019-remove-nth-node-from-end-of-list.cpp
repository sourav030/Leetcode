
class Solution {
public:
    int length(ListNode* head){
        int size=0;
        while(head){
            head=head->next;
            size++;
        }
        return size;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len=length(head);
        int index=len-n;
        if(index==0){
            return head->next;
        }
        ListNode* curr=head;
        int count=0;
        while(curr and count<index-1){
            curr=curr->next;
            count++;
        }
        if(curr and curr->next){
            curr->next=curr->next->next;
        }
        return head;
    }
};