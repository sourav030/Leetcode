class Solution {
  public:
    bool solve(vector<vector<int>>adj, int node, vector<bool>&visited, int parent){
        if(visited[node]==true)return true;
        visited[node]=true;
        for(int i=0; i<adj[node].size(); i++){
            int newNode=adj[node][i];
            if(newNode==parent) continue;
            if(visited[newNode]) return true;
            if(solve(adj,newNode,visited,node)) return true;
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>>adj(V);
        for(int i=0; i<edges.size(); i++){
            int u=edges[i][0];
            int v=edges[i][1];
             adj[u].push_back(v);
            adj[v].push_back(u); 
        }
        vector<bool>visited(V,0);
        for(int i=0; i<V; i++){
            if(!visited[i] and solve(adj,i,visited,-1)){
                return true;
            }
        }
        return false;
    }
};