//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
   void dfsHelper(int u, vector<vector<int>> &temp, vector<bool> &visited) {
        visited[u] = true;
        
        for(const auto &v : temp[u]) {
            if(!visited[v]) {
                dfsHelper(v,temp,visited);
            }
        }
    }
    
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        vector<vector<int>> temp(V);
        vector<bool> visited(V,false);
        
        for(int i=0; i<V; i++) {
            for(int j=0; j<V; j++) {
                if(adj[i][j] == 1 and i!=j) {
                    temp[i].push_back(j);
                    temp[j].push_back(i);
                }
            }
        }
        
        int provinces = 0;
        for(int i=0; i<V; i++) {
            if(!visited[i]) {
                provinces++;
                dfsHelper(i,temp,visited);
            }
        }
        return provinces;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends