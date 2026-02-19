/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        // code here
        vector<int>ans;
        map<int,int>mp;
        queue<pair<Node*, int>>q;
        q.push({root,0});
        
        while(!q.empty()){
            Node* node=q.front().first;
            int idx=q.front().second;
            q.pop();
            mp[idx]=node->data;
            if(node->left){
                q.push({node->left,idx-1});
            }
            if(node->right){
                q.push({node->right,idx+1});
            }
        }
        
        for(auto ele:mp){
            ans.push_back(ele.second);
        }
        return ans;
    }
};