//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//User function Template for C++

class Solution
{
  public:
    vector<int> findOrder(int n, int m, vector<vector<int>> pre) 
    {
        //code here
        vector<vector<int>>adj(n);
        for(int i=0; i<pre.size(); i++){
            adj[pre[i][1]].push_back(pre[i][0]);
        }
        
        vector<int>indegre(n,0);
        
        for(int i=0; i<adj.size(); i++){
            for(int j=0; j<adj[i].size(); j++){
                indegre[adj[i][j]]++;
            }
        }
        
        queue<int>q;
        vector<int>visited(n,0);
        for(int i=0; i<indegre.size(); i++){
            if(indegre[i]==0){
                q.push(i);
                visited[i]=1;
            }
        }
        
        vector<int>ans;
        
        while(!q.empty()){
            int node=q.front();
            ans.push_back(node);
            q.pop();
            for(int i:adj[node]){
                indegre[i]--;
                if(indegre[i]==0 ){
                    q.push(i);
                }
            }
        }
        
        return ans.size() == n ? ans : vector<int>{};

        
    }
};


//{ Driver Code Starts.

int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> prerequisites;

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            prerequisites.push_back({u,v});
        }
        
        vector<int> adj[n];
        for (auto pre : prerequisites)
            adj[pre[1]].push_back(pre[0]);
        
        Solution obj;
        vector <int> res = obj.findOrder(n, m, prerequisites);
        if(!res.size())
            cout<<"No Ordering Possible"<<endl;
        else
            cout << check(n, res, adj) << endl;
    
cout << "~" << "\n";
}
    
    return 0;
}
// } Driver Code Ends