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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* sortNode=nullptr;
        if(!head or !head->next) return head;
        ListNode* current=head;

        while(current){
            ListNode* Next=current->next;

            if(!sortNode or sortNode->val >=current->val ){
                current->next=sortNode;
                sortNode=current;
            }
            else {
                ListNode* temp=sortNode;
                while(temp->next and temp->next->val< current->val){
                    temp=temp->next;
                }
                current->next=temp->next;
                temp->next=current;
            }
                current=Next;
        }
        return sortNode;
    }
};