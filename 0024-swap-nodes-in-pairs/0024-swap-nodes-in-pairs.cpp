class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* newHead = head->next;   
        ListNode* prev = nullptr;
        ListNode* first = head;
        ListNode* second = head->next;

        while (first && second) {
            
            ListNode* nextPair = second->next;   

            second->next = first;
            first->next = nextPair;

          
            if (prev) {
                prev->next = second;
            }

            prev = first;             
            first = nextPair;
            if (first) {
                second = first->next;
            } else {
                second = nullptr;
            }
        }

        return newHead;
    }
};
