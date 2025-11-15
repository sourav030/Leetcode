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
    ListNode* reversed(ListNode* head, ListNode* prev){
        if(!head){
            return prev;
        }
        ListNode* next=head->next;
        head->next=prev;
        return reversed(next,head);
    }
    vector<int> nextLargerNodes(ListNode* head) {
        ListNode* tail=reversed(head,nullptr);
        stack<int>st;
        vector<int>arr;
        while(tail){
            while(!st.empty() and st.top()<=tail->val){
                st.pop();
            }
            if(!st.empty()){
                arr.push_back(st.top());
            }
            else{
                arr.push_back(0);
            }
            st.push(tail->val);
            tail=tail->next;
        }
        reverse(arr.begin(),arr.end());
        return arr;
    }
};