
/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution {
  public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root) {
        // code here
        unordered_map<int,int>mp;
        queue<pair<Node*,int>>q;
        q.push({root,0});
        vector<int>ans;
        int mini=INT_MAX;
        int maxi=INT_MIN;
        
        while(!q.empty()){
            Node* node=q.front().first;
            int index=q.front().second;
            q.pop();
            mini=min(index,mini);
            maxi=max(index,maxi);
            if(mp.find(index)==mp.end()){
                mp[index]=node->data;
            }
            if(node->left) q.push({node->left,index-1});
            if(node->right) q.push({node->right,index+1});
        }
        
        for(int i=mini; i<=maxi ; i++){
            ans.push_back(mp[i]);
        }
        return ans;
    }
};


