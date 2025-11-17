class Solution {
public:
    ListNode* reverse(ListNode* head, ListNode* prev){
        if(!head){
            return prev;
        }
        ListNode* Next = head->next;
        head->next = prev;
        return reverse(Next, head);
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head) return head;

        ListNode* tail = head;

        // Find if we have k nodes
        for(int i = 0; i < k - 1; i++){
             if (!tail->next) return head;
             tail=tail->next;   
        }

      
        ListNode* Next = tail->next;
        tail->next = nullptr;

        ListNode* ans = reverse(head, nullptr);

      
        head->next = reverseKGroup(Next, k);

        return ans;
    }
};
