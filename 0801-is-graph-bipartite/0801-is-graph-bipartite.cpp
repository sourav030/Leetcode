class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> color(V, INT_MAX);

        for(int start = 0; start < V; start++) {
            if(color[start] == INT_MAX) {
                queue<int> q;
                q.push(start);
                color[start] = 0;

                while(!q.empty()) {
                    int node = q.front();
                    q.pop();
                    int c = color[node];

                    for(int neigh : graph[node]) {
                        if(color[neigh] == INT_MAX) {
                            color[neigh] = 1 - c;
                            q.push(neigh);
                        } else if(color[neigh] == c) {
                            return false;
                        }
                    }
                }
            }
        }

        return true;
    }
};
