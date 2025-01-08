class Solution {
    void dfs(int node, vector<vector<int>>& adj, vector<int>& visited) {
        visited[node] = 1;
        for (auto it : adj[node]) {
            if (!visited[it]) {
                dfs(it, adj, visited);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<vector<int>> adjL(V);

        // Convert adjacency matrix to adjacency list
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (adj[i][j] == 1 && i != j) {
                    adjL[i].push_back(j);
                }
            }
        }

        vector<int> visited(V, 0);
        int count = 0;

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                count++;
                dfs(i, adjL, visited);
            }
        }
        return count;
    }
};
