class Solution {
public:
    void solve(int src,vector<vector<int>>&adj, vector<bool>&visited){
        visited[src]=1;
        for(auto neig:adj[src]){
            if(!visited[neig]){
                solve(neig,adj,visited);
            }
        }
        return;
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<vector<int>>adj(n);
        for(int i=0; i<rooms.size(); i++){
            int src=i;
            for(auto ele:rooms[i]){
                adj[src].push_back(ele);
            }
        }
        vector<bool>visited(n,0);
        solve(0,adj,visited);
        for(int i=0; i<visited.size(); i++){
            if(!visited[i]) return false;
        }
        return true;
    }
};