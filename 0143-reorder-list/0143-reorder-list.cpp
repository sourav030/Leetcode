class Solution {
public:
    int length(ListNode* head) {
        int len = 0;
        while (head) {
            len++;
            head = head->next;
        }
        return len;
    }

    void reorderList(ListNode* head) {
        if (!head || !head->next) return;

        int len = length(head);

     
        map<int, ListNode*> mp;
        ListNode* curr = head;
        for (int i = 1; i <= len; i++) {
            mp[i] = curr;
            curr = curr->next;
        }

      
        int left = 1, right = len;
        curr = head;

        while (left < right) {
          
            curr->next = mp[right];
            curr = curr->next;
            right--;

          
            if (left < right) {
                curr->next = mp[left + 1];
                curr = curr->next;
                left++;
            }
        }

        
        curr->next = nullptr;
    }
};
