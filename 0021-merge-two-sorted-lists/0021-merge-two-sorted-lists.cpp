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
    void solve(ListNode* l1, ListNode* l2, ListNode* ans){
        if(!l1 and !l2){
            return;
        }
        if(!l1){
            ans->next=l2;
            return;
        }
        if(!l2){
            ans->next=l1;
            return;
        }
        if(l1->val<l2->val){
            ans->next=l1;
            ans=ans->next;
            solve(l1->next,l2, ans);
        }
        else{
            ans->next=l2;
            ans=ans->next;
            solve(l1,l2->next, ans);
        }
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ans=new ListNode(-1);
        ListNode* tail= ans;
        solve(list1, list2, tail);
        return ans->next;
    }
};