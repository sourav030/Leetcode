class Solution {
    int sizeOfLinkList(ListNode *head) {
        int size = 0;
        ListNode* temp = head;
        while (temp != NULL) {
            temp = temp->next;
            size++;
        }
        return size;
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = sizeOfLinkList(head);
        
        // Edge case: if the node to be removed is the head
        if (n == size) {
            ListNode* newHead = head->next;
            delete head;  
            return newHead;
        }
        
        ListNode* temp = head;
        int stepsToTarget = size - n - 1;
        
        // Move temp to the node before the node to be removed
        while (stepsToTarget > 0 && temp != NULL) {
            temp = temp->next;
            stepsToTarget--;
        }
        
        if (temp != NULL && temp->next != NULL) {
           
            temp->next = temp->next->next;

        }
        
        return head;
    }
};
