class Solution {
public:
    ListNode* reverse(ListNode* head, ListNode* prev){
        if(!head) return prev;
        ListNode* Next = head->next;
        head->next = prev;
        return reverse(Next, head);
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        head = reverse(head, nullptr);  // reverse the list
        if(n == 1){
            // Remove the first node of the reversed list
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return reverse(head, nullptr);
        }

        ListNode* curr = head;
        for(int i = 1; i < n-1 && curr; i++){
            curr = curr->next;
        }

        if(curr && curr->next){
            ListNode* temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
        }

        return reverse(head, nullptr); 
    }
};
