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
        unordered_map<int,int>mp;
        ListNode* tem=head;
        while(tem){
            mp[tem->val]++;
            tem=tem->next;
        }
        ListNode* ans=new ListNode(-1);
        tem=ans;
        ListNode* prev=nullptr;
        while(head){
            if(mp[head->val]==1){
                cout<<mp[head->val]<<" ";
                ans->next=head;
                ans=ans->next;
                prev=head->next;
                ans->next=nullptr;
            }
            else{
                prev=nullptr;
            }
            if(!prev)
              head=head->next;
            else
                head=prev;
        }
        return tem->next;
    }
};