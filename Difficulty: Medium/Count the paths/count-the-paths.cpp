class Solution {
  public:
    int dfs(int src, int dest, vector<vector<int>>& adj, vector<int>& visited, vector<int>& dp) {
        if (src == dest) return 1;
        if (dp[src] != -1) return dp[src];

        visited[src] = 1;
        int totalPaths = 0;

        for (int neighbor : adj[src]) {
            if (!visited[neighbor]) {
                totalPaths += dfs(neighbor, dest, adj, visited, dp);
            }
        }

        visited[src] = 0;
        return dp[src] = totalPaths;
    }

    int countPaths(vector<vector<int>>& edges, int V, int src, int dest) {
        vector<vector<int>> adj(V);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
        }

        vector<int> visited(V, 0);
        vector<int> dp(V, -1);  // Memoization table
        return dfs(src, dest, adj, visited, dp);
    }
};
