class Solution {
public:
    int count=0;
    void solve( vector<vector<pair<int,int>>>&adj, int src,vector<bool>&visited){
        visited[src]=1;
        for(auto ele:adj[src]){
            int node=ele.first;
            int tag=ele.second;
            if(!visited[node]){
                if(tag==1){
                    count++;
                }
                
                solve(adj,node,visited);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int,int>>>adj(n);

        for(int i=0; i<connections.size(); i++){
            int src=connections[i][0];
            int dis=connections[i][1];
            adj[src].push_back({dis,1});
            adj[dis].push_back({src,0});
        }
        vector<bool>visited(n,0);
        solve(adj,0,visited);
        return count;
    }
};