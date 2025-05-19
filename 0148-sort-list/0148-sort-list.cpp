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
   ListNode* findmid(ListNode* head)
    {
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast!=NULL and fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* merge(ListNode* left, ListNode* right)
    {
        if(left==NULL)
        {
            return right;
        }
        if(right==NULL)
        {
            return right;
        }
        ListNode* new_node=new ListNode(-1);
        ListNode* tem=new_node;
        while(left!=NULL and right !=NULL)
        {
            if(left->val < right->val)
            {
                tem->next=left;
                tem=left;
                left=left->next;
            }
            else
            {
                 tem->next=right;
                tem=right;
                right=right->next;
            }
        }
        while(left!=NULL)
        {
             tem->next=left;
                tem=left;
                left=left->next;
        }
        while(right!=NULL)
        {
              tem->next=right;
                tem=right;
                right=right->next;
        }
        return new_node->next;
    }
public:
    ListNode* sortList(ListNode* head) {
        
        if(head==NULL or head->next==NULL)
        {
            return head;
        }
        ListNode* mid=findmid(head);
        ListNode* left= head;
       ListNode* right=mid->next;
        mid->next=NULL;
        // recursive call for sorted the list;
        left=sortList(left);
        right=sortList(right);
        // merge botht list;
        ListNode* result= merge(left, right);
        return result;
        
    }
};