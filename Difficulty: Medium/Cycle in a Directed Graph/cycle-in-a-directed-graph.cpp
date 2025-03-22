//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool solve(vector<vector<int>>& adj, vector<bool> &path,vector<bool> &visited, int index){
        path[index]=1;
        visited[index]=1;
        for(int i=0; i<adj[index].size(); i++){
            int Node=adj[index][i];
            if(path[Node]){
                return true;
            }
            if(!visited[Node]){
            bool a=solve(adj,path,visited,Node);
            if(a)return 1;}
            
        }
        path[index]=0;
        return false;
    }
    bool isCyclic(vector<vector<int>> &adj) {
        // code here
        int v=adj.size();
        vector<bool>path(v,0);
        vector<bool>visited(v,0);
        for(int i=0; i<v; i++){
            if(solve(adj,path,visited,i)){
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
        cout << obj.isCyclic(adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends