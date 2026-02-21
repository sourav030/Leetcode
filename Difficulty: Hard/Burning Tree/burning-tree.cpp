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
                q.push(node->left);
                mp[node->data].push_back(node->left->data);
                mp[node->left->data].push_back(node->data);
            }
            if(node->right){
                q.push(node->right);
                mp[node->data].push_back(node->right->data);
                mp[node->right->data].push_back(node->data);
            }
        }
    }
    int minTime(Node* root, int target) {
        // code here
        buildGraph(root);
        unordered_set<int>st;
        int time=-1;
        queue<int>q;
        q.push(target);
        while(!q.empty()){
            int n=q.size();
            for(int i=0; i<n; i++){
                int node=q.front();
                q.pop();
                st.insert(node);
                for(auto ele:mp[node]){
                    if(st.find(ele)==st.end()){
                        q.push(ele);
                    }
                }
            }
            time++;
        }
        return time;
        
    }
};