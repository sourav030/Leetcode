class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return nullptr;

        ListNode* start = head;
        ListNode* tail = head;

        head = head->next;
        tail->next = nullptr;

        while (head) {
            if (head->val != tail->val) {
                tail->next = head;
                tail = tail->next;
            }
            head = head->next;
        }

        tail->next = nullptr;  // important fix
        return start;
    }
};
