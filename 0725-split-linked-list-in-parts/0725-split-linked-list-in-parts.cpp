class Solution {
public:
    vector<ListNode*> arr;

    int len(ListNode* head) {
        int count = 0;
        while (head) {
            head = head->next;
            count++;
        }
        return count;
    }

    ListNode* check(ListNode* head, int &remainder, int numberNode) {
        if (!head) {
            arr.push_back(nullptr);
            return nullptr;
        }

        int currentPartSize = numberNode;
        if (remainder > 0) {
            currentPartSize++;
            remainder--;
        }

        ListNode* tail = head;
        for (int i = 0; i < currentPartSize - 1; i++) {
            if (tail) tail = tail->next;
        }

        ListNode* nextHead = nullptr;
        if (tail) {
            nextHead = tail->next;
            tail->next = nullptr;
        }

        arr.push_back(head);
        return nextHead;
    }

    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int length = len(head);
        int numberNode = length / k;
        int remainder = length % k;

        for (int i = 0; i < k; i++) {
            head = check(head, remainder, numberNode);
        }
        
        return arr;
    }
};