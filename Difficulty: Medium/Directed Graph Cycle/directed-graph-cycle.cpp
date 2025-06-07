class Solution {
  public:
    bool solve(vector<bool>&visited,vector<bool>&path, vector<vector<int>>&adj, int node){
        visited[node]=true;
        path[node]=true;
        for(int newNode:adj[node]){
            if(path[newNode]) return true;
            if(!visited[newNode] and solve(visited,path,adj,newNode)){
                return true;
            }
        }
        path[node]=false;
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>>adj(V);
        for(auto ele:edges){
            adj[ele[0]].push_back(ele[1]);
        }
        vector<bool>visited(V,0);
        vector<bool>path(V,0);
        for(int i=0; i<V; i++){
            if(!visited[i] and solve(visited,path,adj,i)){
                return true;
            }
        }
        return false;
    }
};