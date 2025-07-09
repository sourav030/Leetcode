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
    struct comp {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val; // min-heap
    }
};
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0){
            return nullptr;
        }
       priority_queue<ListNode*, vector<ListNode*>, comp> pq;

        for(int i=0; i<lists.size(); i++){
            if(lists[i])
            pq.push(lists[i]);
        }

        ListNode* head=new ListNode(-1);
        ListNode* tail=head;

        while(!pq.empty()){
            ListNode* temp=pq.top();
            pq.pop();
            tail->next=temp;
            tail=tail->next;
            if(temp->next){
                pq.push(temp->next);
            }
        }

        return head->next;
    }
};