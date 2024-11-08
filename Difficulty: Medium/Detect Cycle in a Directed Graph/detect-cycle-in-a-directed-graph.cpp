//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool detectCycleDfs(vector<bool> &visited, vector<bool> &path, vector<vector<int>> adj, int Node){
        visited[Node]=1;
        path[Node]=1;
        for(int i=0; i<adj[Node].size(); i++){
            if(path[adj[Node][i]]){
                return 1;
            }
            if(visited[adj[Node][i]]){
                continue;
            }
            if(detectCycleDfs(visited,path, adj, adj[Node][i])){
                return 1;
            }
        }
        path[Node]=0;
        return 0;
    }
    bool isCyclic(int V, vector<vector<int>> adj) {
        // code here
        vector<bool> visited(V,0);
        vector<bool> path(V,0);
        
        for(int i=0; i<V; i++){
            if(!visited[i] and detectCycleDfs(visited,path,adj,i)){
                return 1;
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends