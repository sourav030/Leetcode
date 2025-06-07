class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        // Build adjacency list
        vector<vector<int>> adj(n);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        int ans = INT_MAX;
        
        for (int start = 0; start < n; start++) {
            vector<int> dist(n, -1);
            vector<int> parent(n, -1);
            queue<int> q;
            
            dist[start] = 0;
            q.push(start);
            
            while (!q.empty()) {
                int node = q.front(); q.pop();
                
                for (auto &neighbor : adj[node]) {
                    if (dist[neighbor] == -1) {
                        // Not visited
                        dist[neighbor] = dist[node] + 1;
                        parent[neighbor] = node;
                        q.push(neighbor);
                    } else if (parent[node] != neighbor) {
                        // Visited and not parent → cycle detected
                        int cycleLen = dist[node] + dist[neighbor] + 1;
                        ans = min(ans, cycleLen);
                    }
                }
            }
        }
        
        return ans == INT_MAX ? -1 : ans;
    }
};
