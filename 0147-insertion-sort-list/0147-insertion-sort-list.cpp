/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
    if (head == NULL || head->next == NULL) return head;

    ListNode* curr = head;
    head = head->next;
    curr->next = NULL;

    while (head) {
        ListNode* Next = head->next;

        if (head->val < curr->val) {
            head->next = curr;
            curr = head;
        } else {
            ListNode* tail = curr;
            ListNode* prev = NULL;

            while (tail && tail->val < head->val) {
                prev = tail;
                tail = tail->next;
            }

            if (prev == NULL) {
                head->next = curr;
                curr = head;
            } else {
                prev->next = head;
                head->next = tail;
            }
        }

        head = Next;
    }

    return curr;
}

};