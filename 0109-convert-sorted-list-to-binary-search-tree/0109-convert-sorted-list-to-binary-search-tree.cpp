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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* buildtree(vector<int>v , int start, int end)
    {
        if(start>end)
        {
            return NULL;
        }
        int mid=(start+end)/2;
        TreeNode* root= new TreeNode(v[mid]);
        root->left=buildtree(v,start,mid-1);
        root->right=buildtree(v,mid+1,end);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int>v;
        while(head!=NULL)
        {
            v.push_back(head->val);
            head=head->next;
        }
        return buildtree(v,0,v.size()-1);
    }
    
    // first of all create a vector and the value of linked list
    //second of create function buildtree such it find the mid value and add on root
    //find binary seach technique to add left and right part of tree
};