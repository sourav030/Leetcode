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
    map<int,map<int,vector<int>> >mp;
    void solve(TreeNode* root, int Xaxis, int height){
        if(!root){
            return ;
        }
        mp[Xaxis][height].push_back(root->val);
        solve(root->left,Xaxis-1,height+1);
        solve(root->right,Xaxis+1,height+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        solve(root,0,0);
        vector<vector<int>>ans;
        for(auto ele:mp){
           vector<int> col;
            for (auto &ele2 : ele.second) {
                auto temp = ele2.second;
                sort(temp.begin(), temp.end());
                col.insert(col.end(), temp.begin(), temp.end());
            }
            ans.push_back(col);   // ✅ yaha hona chahiye

        }
        return ans;
    }
};