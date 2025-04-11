//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User Function Template
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<vector<pair<int,int>>>adj(V);
        for(int i=0; i<edges.size(); i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int w=edges[i][2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        
        vector<int>Dis(V,INT_MAX);
        
       priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
       pq.push({0,src});
       Dis[src]=0;
       
       while(!pq.empty()){
           int dis=pq.top().first;
           int Node=pq.top().second;
           pq.pop();
           
           for(auto it:adj[Node]){
               int neigh=it.first;
               int w=it.second;
               if(dis+w<Dis[neigh]){
                   Dis[neigh]=dis+w;
                   pq.push({Dis[neigh],neigh});
               }
           }
       }
       
       return Dis;
        
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> edges;
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            edges.push_back({u, v, w});
            edges.push_back({v, u, w});
        }
        int src;
        cin >> src;
        cin.ignore();

        Solution obj;
        vector<int> res = obj.dijkstra(V, edges, src);

        for (int i = 0; i < V; i++)
            cout << res[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends