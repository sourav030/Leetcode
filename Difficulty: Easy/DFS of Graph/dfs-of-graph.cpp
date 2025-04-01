//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    void solve(vector<int>& ans, vector<bool>& visited,vector<vector<int>>& adj,int index){
        visited[index]=1;
        ans.push_back(index);
        for(int i=0; i<adj[index].size(); i++){
            if(!visited[adj[index][i]]){
                solve(ans,visited,adj,adj[index][i]);
            }
        }
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        
        vector<int>ans;
        int v=adj.size();
        vector<bool>visited(v,0);
        for(int i=0; i<v; i++){
            if(!visited[i]){
                solve(ans,visited,adj,i);
            }
        }
        return ans;
        
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        int V;
        cin >> V;
        cin.ignore();
        vector<vector<int>> adj(
            V); // Use vector of vectors instead of array of vectors.

        for (int i = 0; i < V; i++) {
            string input;
            getline(cin, input);
            int num;
            vector<int> node;
            stringstream ss(input);
            while (ss >> num) {
                node.push_back(num);
            }
            adj[i] = node;
        }

        Solution obj;
        vector<int> ans = obj.dfs(adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends