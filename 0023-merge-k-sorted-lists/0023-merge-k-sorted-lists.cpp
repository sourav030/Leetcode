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
    struct Compare {
    bool operator()(ListNode* a, ListNode* b) const {
        return a->val > b->val; // min-heap
    }
};

    ListNode* mergeKLists(vector<ListNode*>& lists) {
       priority_queue<ListNode*, vector<ListNode*>, Compare> pq;
        ListNode* head=new ListNode(-1);
        ListNode* tail=head;
        for(auto ele:lists){
            if(ele)
            pq.push(ele);
        }
        while(!pq.empty()){
            ListNode* a=pq.top();
            pq.pop();
            tail->next=a;
            tail=a;
            
            if(a->next) pq.push(a->next);
        }
        return head->next;
    }
};