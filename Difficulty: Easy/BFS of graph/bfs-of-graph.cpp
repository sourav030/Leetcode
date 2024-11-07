//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(vector<vector<int>> &adj) {
        // Code here
        int v=adj.size();
        vector<bool> visited(v,0);
        vector<int>ans;
        visited[0]=1;
        queue<int>q;
        q.push(0);
        while(!q.empty()){
            int Node=q.front();
            q.pop();
            ans.push_back(Node);
            for(int j=0; j<adj[Node].size(); j++){
                if(!visited[adj[Node][j]]){
                    q.push(adj[Node][j]);
                    visited[adj[Node][j]]=1;
                }
            }
        }
        return ans;
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        // Now using vector of vectors instead of array of vectors
        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        Solution obj;
        vector<int> ans = obj.bfsOfGraph(adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends