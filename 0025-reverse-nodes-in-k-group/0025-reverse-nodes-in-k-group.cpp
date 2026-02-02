class Solution {
public:
    ListNode* reverse(ListNode* head, int k){
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while(curr && k--){
            ListNode* Next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = Next;
        }
        return prev;        
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head) return head;

      
        ListNode* temp = head;
        for(int i=0; i<k; i++){
            if(!temp) return head;   
            temp = temp->next;
        }

       
        ListNode* newHead = reverse(head, k);

     
        head->next = reverseKGroup(temp, k);

        return newHead;
    }
};
