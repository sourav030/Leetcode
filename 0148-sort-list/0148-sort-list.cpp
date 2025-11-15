class Solution {
public:
    ListNode* findMid(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* merge(ListNode* a, ListNode* b){
        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;

        while (a && b){
            if (a->val < b->val){
                tail->next = a;
                a = a->next;
            } else {
                tail->next = b;
                b = b->next;
            }
            tail = tail->next;
        }

        tail->next = (a ? a : b);
        return dummy->next;
    }

    ListNode* sortList(ListNode* head) {
        if (!head || !head->next)
            return head;

        ListNode* mid = findMid(head);
        ListNode* right = mid->next;
        mid->next = NULL;

        ListNode* leftSorted = sortList(head);
        ListNode* rightSorted = sortList(right);

        return merge(leftSorted, rightSorted);
    }
};
