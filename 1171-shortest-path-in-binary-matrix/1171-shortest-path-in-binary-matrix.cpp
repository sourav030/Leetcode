class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // if start or end is blocked
        if (grid[0][0] == 1 || grid[n-1][m-1] == 1)
            return -1;

        // 8 possible moves
        vector<int> dr = {-1, -1, -1, 0, 0, 1, 1, 1};
        vector<int> dc = {-1, 0, 1, -1, 1, -1, 0, 1};

        queue<pair<int,int>> q;
        q.push({0,0});
        grid[0][0] = 1;  // distance from start = 1

        while(!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            int dist = grid[r][c];
            q.pop();

            // reached destination
            if (r == n-1 && c == m-1)
                return dist;

            // explore all 8 directions
            for (int i = 0; i < 8; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 0) {
                    grid[nr][nc] = dist + 1;
                    q.push({nr, nc});
                }
            }
        }
        return -1; // no path
    }
};
