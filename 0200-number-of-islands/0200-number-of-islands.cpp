class Solution {
public:
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};
    int row, col;

    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int r, int c) {
        visited[r][c] = true;

        for (int i = 0; i < 4; i++) {
            int new_r = r + dx[i];
            int new_c = c + dy[i];

            if (new_r >= 0 && new_r < row && new_c >= 0 && new_c < col
                && !visited[new_r][new_c] && grid[new_r][new_c] == '1') {
                dfs(grid, visited, new_r, new_c);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        row = grid.size();
        col = grid[0].size();
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        int count = 0;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (!visited[i][j] && grid[i][j] == '1') {
                    count++;
                    dfs(grid, visited, i, j);
                }
            }
        }

        return count;
    }
};
