class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return nullptr;

        unordered_map<int,int> mp;
        ListNode* temp = head;
        
        // count frequencies
        while (temp) {
            mp[temp->val]++;
            temp = temp->next;
        }
        
        ListNode* ans = new ListNode(-1);
        ListNode* tail = ans;
        
        while (head) {
            if (mp[head->val] == 1) {
                tail->next = head;   
                tail = tail->next;   
            }
            head = head->next;
        }
        
        tail->next = nullptr;  
        
        return ans->next;
    }
};
