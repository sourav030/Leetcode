class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        int shortest = INT_MAX;

        for (int i = 0; i < n; ++i) {
            vector<int> dist(n, -1);
            vector<int> parent(n, -1);
            queue<int> q;
            dist[i] = 0;
            q.push(i);

            while (!q.empty()) {
                int node = q.front(); q.pop();
                for (int neighbor : adj[node]) {
                    if (dist[neighbor] == -1) {
                        dist[neighbor] = dist[node] + 1;
                        parent[neighbor] = node;
                        q.push(neighbor);
                    } else if (parent[node] != neighbor) {
                        // Cycle found
                        shortest = min(shortest, dist[node] + dist[neighbor] + 1);
                    }
                }
            }
        }

        return shortest == INT_MAX ? -1 : shortest;
    }
};
