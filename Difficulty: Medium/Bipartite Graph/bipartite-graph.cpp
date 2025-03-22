//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
   bool isBipartite(vector<vector<int>>& adj) {
    int V = adj.size();
    vector<int> colors(V, -1);  // Use int instead of bool (-1 for uncolored)
    vector<bool> visited(V, false);
    
    queue<pair<int, int>> q;

    for (int i = 0; i < V; i++) { // Check for disconnected components
        if (!visited[i]) {
            q.push({i, 0});
            visited[i] = true;
            colors[i] = 0;

            while (!q.empty()) {
                int node = q.front().first;
                int color = q.front().second;
                q.pop();

                for (auto neigh : adj[node]) {
                    if (colors[neigh] == color) { 
                        return false; // Conflict detected, graph is NOT bipartite
                    }
                    if (!visited[neigh]) {
                        visited[neigh] = true;
                        colors[neigh] = !color; // Assign opposite color
                        q.push({neigh, !color});
                    }
                }
            }
        }
    }
    return true; // If no conflicts found, graph is bipartite
}
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isBipartite(adj);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends