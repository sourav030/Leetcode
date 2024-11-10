//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        vector<int> ans(N,-1);
        vector<int>adj[N];
        // graph bna liya maine
        for(int i=0; i<M; i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool>visited(N,0);
        queue<int> q;
        q.push(src);
        visited[src]=1;
        ans[src]=0;
        while(!q.empty()){
            int Node=q.front();
            q.pop();
            for(int i=0; i<adj[Node].size(); i++){
                int neighbour=adj[Node][i];
                if(visited[neighbour]){
                    continue;
                }
                visited[neighbour]=1;
                q.push(neighbour);
                ans[neighbour]=ans[Node]+1;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    
cout << "~" << "\n";
}
}

// } Driver Code Ends