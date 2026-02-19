/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int>ans;
    map<int,int>mp;
    
    vector<int> topView(Node *root) {
        // code here
        queue<pair<Node*,int>>q;
        q.push({root,0});
        
        while(!q.empty()){
            Node* node=q.front().first;
            int idx=q.front().second;
            q.pop();
            if(mp.find(idx)==mp.end())
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