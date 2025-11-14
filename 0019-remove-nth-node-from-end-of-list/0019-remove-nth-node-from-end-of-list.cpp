class Solution {
public:
    ListNode* reverse(ListNode* node, ListNode* prev){
        if (!node) return prev;
        ListNode* Next = node->next;
        node->next = prev;
        return reverse(Next, node);
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {

        // Reverse list
        ListNode* rev = reverse(head, nullptr);

    
        if (n == 1) {
            return reverse(rev->next, nullptr);
        }

      
        ListNode* curr = rev;
        for (int i = 1; i < n - 1; i++) {
            curr = curr->next;
        }

        
        if (curr->next) {
            curr->next = curr->next->next;
        }

       
        return reverse(rev, nullptr);
    }
};
