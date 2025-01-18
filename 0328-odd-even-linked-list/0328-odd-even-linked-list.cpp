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
    void solve(ListNode* &ans, ListNode* head) {
    ListNode* temp = head;
    while (temp != NULL) {
        ListNode* newNode = new ListNode(temp->val);
        ans->next = newNode;
        ans = ans->next;
        temp = temp->next;
        if (temp != NULL) temp = temp->next; // Skip to next odd/even node
    }
}

ListNode* oddEvenList(ListNode* head) {
    if (head == NULL) return NULL;

    // Dummy nodes for odd and even lists
    ListNode* oddDummy = new ListNode(-1);
    ListNode* evenDummy = new ListNode(-1);

    // Pointers to build odd and even lists
    ListNode* odd = oddDummy;
    ListNode* even = evenDummy;

    // Split the list into odd and even
    solve(odd, head);           // Odd nodes
    solve(even, head->next);    // Even nodes

    odd->next = evenDummy->next; // Merge even list at the end of odd list
    even->next = NULL;           // Terminate even list

    return oddDummy->next;       // Return head of the new list
}

};