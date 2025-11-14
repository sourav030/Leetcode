class Solution {
public:
    int length(ListNode* head){
        int len = 0;
        while (head) {
            len++;
            head = head->next;
        }
        return len;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        // 1. find length
        int len = length(head);

        // 2. effective rotation
        k = k % len;
        if (k == 0) return head;

        // 3. find split point (len - k)
        int n = len - k;

        ListNode* curr = head;
        ListNode* prev = nullptr;

        // move n - 1 steps
        for (int i = 0; i < n - 1; i++) {
            curr = curr->next;
        }

        // 4. split
        prev = curr;          // new tail
        ListNode* newHead = curr->next;   // start of rotated part
        prev->next = nullptr; // cut the list

        // 5. find end of rotated part
        ListNode* temp = newHead;
        while (temp->next) {
            temp = temp->next;
        }

        // 6. attach old head at end
        temp->next = head;

        // 7. new head
        return newHead;
    }
};
