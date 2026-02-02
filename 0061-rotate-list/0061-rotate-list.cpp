class Solution {
public:

    int len(ListNode* head){
        int l = 0;
        while(head){
            l++;
            head = head->next;
        }
        return l;
    }

    ListNode* rotateRight(ListNode* head, int k) {

      
        if(!head || !head->next || k == 0)
            return head;

        int l = len(head);

        k = k % l;
        if(k == 0)
            return head;

      
        int steps = l - k - 1;

        ListNode* temp = head;
        while(steps--){
            temp = temp->next;
        }

        ListNode* newHead = temp->next;

        
        temp->next = NULL;

      
        ListNode* tail = newHead;
        while(tail->next){
            tail = tail->next;
        }

        
        tail->next = head;

        return newHead;
    }
};
