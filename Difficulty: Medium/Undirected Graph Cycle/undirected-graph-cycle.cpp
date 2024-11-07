//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool DfsCycle(vector<bool> &visited,int Node, int Parent, vector<vector<int>>& adj)
    {
        visited[Node]=1;
        for(int i=0; i<adj[Node].size(); i++){
            if(Parent==adj[Node][i])
            continue;
            if(visited[adj[Node][i]])
             return 1;
            if(DfsCycle(visited,adj[Node][i], Node,adj)){
                return 1;
            }
        }
        return 0;
    }
    bool isCycle(vector<vector<int>>& adj) {
        // Code here
        int n=adj.size();
        vector<bool>visited(n,0);
        for(int i=0; i<n; i++){
         if(!visited[i] and DfsCycle(visited,i,-1,adj)){
             return 1;
         }   
        }
        return 0;
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
        bool ans = obj.isCycle(adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends