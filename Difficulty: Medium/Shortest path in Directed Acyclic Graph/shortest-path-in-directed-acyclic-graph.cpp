//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  void topo(int node, vector<vector<pair<int, int>>>& adj, vector<int>& visited, stack<int>& s) {
    visited[node] = 1;
    for (auto ele : adj[node]) { // ele is a pair<int, int>
        if (!visited[ele.first]) { // ele.first refers to the adjacent node
            topo(ele.first, adj, visited, s);
        }
    }
    s.push(node);
}

    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        vector<vector<pair<int,int>>>adj(V);
        for(auto ed:edges){
            int u=ed[0];
            int v=ed[1];
            int weight=ed[2];
            adj[u].push_back(make_pair(v,weight));
        }
        
        // perform a topological sort
        stack<int>s;
        vector<int>visited(V,0);
        for(int i=0; i<V; i++){
            if(!visited[i]){
                topo(i,adj, visited, s);
            }
        }
        
        vector<int>dis(V,INT_MAX);
        dis[0]=0;
        while(!s.empty()){
         int node=s.top();
         s.pop();
         for(auto ele:adj[node]){
             int neigh=ele.first;
             int weight=ele.second;
             if(dis[node] != INT_MAX and dis[node]+weight<dis[neigh]){
                 dis[neigh]=dis[node]+weight;
             }
         }
        }
        for(int i=0; i<V; i++){
            if(dis[i]==INT_MAX){
                dis[i]=-1;
            }
        }
        return dis;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends