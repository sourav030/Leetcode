/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
   unordered_map<TreeNode*, vector<TreeNode*>> graph;

void buildGraph(TreeNode* root) {
    if (!root) return;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* node = q.front(); q.pop();

        if (node->left) {
            graph[node].push_back(node->left);
            graph[node->left].push_back(node);
            q.push(node->left);
        }

        if (node->right) {
            graph[node].push_back(node->right);
            graph[node->right].push_back(node);
            q.push(node->right);
        }
    }
}

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
            buildGraph(root);
            int dis=0;
            queue<pair<TreeNode*,int>>q;
            q.push({target,0});
            vector<int>ans;
            vector<bool>visited(500,0);
            visited[target->val]=1;
            while(!q.empty()){
                TreeNode* node=q.front().first;
                int dis=q.front().second;
                if(dis==k){
                    ans.push_back(node->val);
                }
                q.pop();
                for(auto ele:graph[node]){
                    if(visited[ele->val]==0){
                        visited[ele->val]=1;
                        q.push({ele,dis+1});
                    }
                }
            }
           return ans;
    }
};