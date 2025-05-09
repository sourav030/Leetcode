class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& component) {
        visited[node] = true;
        component.push_back(node);
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, adj, visited, component);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n, false);
        int completeComponents = 0;

        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                vector<int> component;
                dfs(i, adj, visited, component);

                int nodeCount = component.size();
                int edgeCount = 0;

                for (int node : component) {
                    edgeCount += adj[node].size();
                }

                edgeCount /= 2;

                if (edgeCount == (nodeCount * (nodeCount - 1)) / 2) {
                    completeComponents++;
                }
            }
        }

        return completeComponents;
    }
};
