class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return nullptr;

        ListNode* p1 = headA;
        ListNode* p2 = headB;

        while (p1 != p2) {
            // When p1 reaches the end, switch to headB
            p1 = (p1 == nullptr) ? headB : p1->next;
            // When p2 reaches the end, switch to headA
            p2 = (p2 == nullptr) ? headA : p2->next;
        }

        // Either intersection node or nullptr
        return p1;
    }
};
