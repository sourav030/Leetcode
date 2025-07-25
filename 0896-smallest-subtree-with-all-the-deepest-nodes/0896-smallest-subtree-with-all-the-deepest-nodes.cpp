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
 #include<bits/stdc++.h>
class Solution {
public:
    vector<TreeNode*>depestNode(TreeNode* root){
        unordered_map<int,vector<TreeNode*>>mp;
        int maxi=INT_MIN;
        queue<pair<TreeNode*, int>>q;
        q.push({root,0});
        while(!q.empty()){
            TreeNode* Node=q.front().first;
            int level=q.front().second;
            q.pop();
            maxi=max(maxi,level);
            if(!Node->left and !Node->right){
                mp[level].push_back(Node);
            }
            if(Node->left){
                q.push({Node->left,level+1});
            }
            if(Node->right){
                q.push({Node->right,level+1});
            }
        }
        return mp[maxi];
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return nullptr;
        if(root==p or root==q){
            return root;
        }
        TreeNode* left=lowestCommonAncestor(root->left,p,q);
        TreeNode* right=lowestCommonAncestor(root->right,p,q);
        if(left and right) {
            return root;
        }
        if(left){
            return left;
        }
        else{
            return right;
        }
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if(!root or !root->left and !root->right){
            return root;
        }
        vector<TreeNode*>leafNode=depestNode(root);
        while(leafNode.size()>1){
            TreeNode* node=leafNode.back();
            leafNode.pop_back();
            TreeNode* node2=leafNode.back();
            leafNode.pop_back();
            TreeNode* result=lowestCommonAncestor(root,node,node2);
            leafNode.push_back(result);
        }
        return leafNode.back();
    }   
};