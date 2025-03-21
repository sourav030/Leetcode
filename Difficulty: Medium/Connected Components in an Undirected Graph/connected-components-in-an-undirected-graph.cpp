//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Matrix {
  public:
    template <class T>
    static void input(vector<vector<T>> &A, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A) {
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends


class Solution {
  public:
      vector<vector<int>>ans;
    void solve(vector<vector<int>> &adj,vector<bool> &visited,int i){
        queue<int>q;
        q.push(i);
        visited[i]=1;
        vector<int>a;
        while(!q.empty()){
            int Node=q.front();
            q.pop();
            a.push_back(Node);
            for(int ad:adj[Node]){
                if(!visited[ad]){
                    q.push(ad);
                    visited[ad]=1;
                }
            }
        }
        sort(a.begin(),a.end());
        ans.push_back(a);
    }  
    vector<vector<int>> connectedcomponents(int V, vector<vector<int>>& edges) {
        // code here
      vector<vector<int>>adj(V);
      
      for(int i=0; i<edges.size(); i++){
          int u=edges[i][0];
          int v=edges[i][1];
          adj[u].push_back(v);
          adj[v].push_back(u);
      }
      vector<bool>visited(V,0);
      for(int i=0; i<V; i++){
          if(!visited[i]){
              solve(adj,visited,i);
          }
      }
      return ans;
      
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int e;
        scanf("%d", &e);

        int v;
        scanf("%d", &v);

        vector<vector<int>> edges(e, vector<int>(2));
        Matrix::input(edges, e, 2);

        Solution obj;
        vector<vector<int>> res = obj.connectedcomponents(v, edges);
        sort(res.begin(), res.end());
        for (const auto &component : res) {
            for (int node : component) {
                cout << node << " ";
            }
            cout << endl;
        }

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends