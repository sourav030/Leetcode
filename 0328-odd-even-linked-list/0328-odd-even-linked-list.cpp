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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* curr=new ListNode(-1);
        ListNode* newNode=curr;
        int count=1;
        ListNode* tem=head;
        while(tem){
            if(count%2!=0){
                ListNode* new_Node=new ListNode(tem->val);
                newNode->next=new_Node;
                newNode=newNode->next;
            }
            tem=tem->next;
            count++;
        }
        tem=head;
        count=1;
        while(tem){
            if(count%2==0){
                ListNode* new_Node=new ListNode(tem->val);
                newNode->next=new_Node;
                newNode=newNode->next;
            }
            count++;
            tem=tem->next;
        }
        return curr->next;;

    }
};