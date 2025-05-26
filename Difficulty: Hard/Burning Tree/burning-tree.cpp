/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    unordered_map<int,vector<int>>mp;
    void buildGraph(Node* root){
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            Node* node=q.front();
            q.pop();
            if(node->left){
                mp[node->data].push_back(node->left->data);
                mp[node->left->data].push_back(node->data);
                q.push(node->left);
            }
            if(node->right){
                 mp[node->data].push_back(node->right->data);
                mp[node->right->data].push_back(node->data);
                q.push(node->right);
            }
        }
    }
    
    int minTime(Node* root, int target) {
        // code here
        buildGraph(root);
        vector<bool>visited(pow(10,5),0);
        queue<pair<int,int>>q;
        q.push({target,0});
        int time=-1;
        visited[target]=1;
        while(!q.empty()){
            auto node=q.front();
            time=max(time,node.second);
            q.pop();
            
            for(auto ele:mp[node.first]){
                if(visited[ele]==0){
                    visited[ele]=1;
                    q.push({ele,node.second+1});
                }
            }
            
        }
        return time;
        
    }
};