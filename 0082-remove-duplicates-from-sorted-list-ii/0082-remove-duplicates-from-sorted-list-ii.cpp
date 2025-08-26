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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* ans=new ListNode(-1);
        ListNode* tail1=head;
        ListNode* tail=ans;
        unordered_map<int,int>mp;

        while(tail1){
            mp[tail1->val]++;
            tail1=tail1->next;
        }

        while(head){
            if(mp[head->val]==1){
                tail->next=head;
                tail=tail->next;
                head=head->next;
                tail->next =nullptr;
            }
            else{
                head=head->next;
            }
        }
        return ans->next;
    }
};