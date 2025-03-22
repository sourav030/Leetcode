//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

//Back-end complete function Template for C++


// } Driver Code Ends

class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        // code here
        int V=adj.size();
        vector<int>visited(V,0);
        vector<int>distance(V,-1);
        queue<pair<int,int>>q;
        q.push({src,0});
        visited[src]=1;
        distance[src]=0;
        
        while(!q.empty()){
            int node=q.front().first;
            int dis=q.front().second;
            distance[node]=dis;
            q.pop();
            for(auto Node:adj[node]){
                if(!visited[Node]){
                    q.push({Node,dis+1});
                    visited[Node]=1;
                }
            }
        }
        return distance;
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
            adj[v].push_back(u);
        }

        int src;
        cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(adj, src);

        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
        cout << "~\n";
    }
}

// } Driver Code Ends