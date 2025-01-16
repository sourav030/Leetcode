//{ Driver Code Starts
#include <cstdio> // for freopen
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    /*  Function to implement Bellman Ford
     *   edges: vector of vectors which represents the graph
     *   src: source vertex
     *   V: number of vertices
     */
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        vector<int>Distance(V,1e8);
        Distance[src]=0;
        for(int i=0; i<V-1; i++){
            for(int j=0; j<edges.size(); j++){
                int source=edges[j][0];
                int destination=edges[j][1];
                int weight=edges[j][2];
                if(Distance[source]==1e8){
                    continue;
                }
                if(Distance[source]+weight<Distance[destination]){
                    Distance[destination]=Distance[source]+weight;
                }
            }
        }
        
         for(int j=0; j<edges.size(); j++){
                int source=edges[j][0];
                int destination=edges[j][1];
                int weight=edges[j][2];
                if(Distance[source]==1e8){
                    continue;
                }
                if(Distance[source]+weight<Distance[destination]){
                    vector<int>ans;
                    ans.push_back(-1);
                    return ans;
                    Distance[destination]=Distance[source]+weight;
                }
            }
            
            return Distance;
        
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int N, m;
        cin >> N >> m;

        vector<vector<int> > edges;

        for (int i = 0; i < m; ++i) {
            int u, v, w;
            cin >> u >> v >> w;

            vector<int> edge(3);
            edge[0] = u;
            edge[1] = v;
            edge[2] = w;
            edges.push_back(edge);
        }

        int src;
        cin >> src;
        cin.ignore();

        Solution obj;
        vector<int> res = obj.bellmanFord(N, edges, src);

        for (size_t i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends