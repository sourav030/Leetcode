class Solution {
public:
    vector<int> row = {1, -1, 0, 0};
    vector<int> col = {0, 0, 1, -1};
    int n, m;

    bool valid(int a, int b) {
        return (a >= 0 && a < n && b >= 0 && b < m);
    }

    bool solve(vector<vector<bool>>& visited, vector<vector<char>>& grid, int r, int c, int pr, int pc, char ch) {
        visited[r][c] = true;

        for (int i = 0; i < 4; i++) {
            int newRow = r + row[i];
            int newCol = c + col[i];

            if (!valid(newRow, newCol))
                continue;

            if (grid[newRow][newCol] != ch)
                continue;

            if (newRow == pr && newCol == pc)
                continue;

            if (visited[newRow][newCol])
                return true;

            if (!visited[newRow][newCol]) {
                if (solve(visited, grid, newRow, newCol, r, c, ch))
                    return true;
            }
        }
        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j]) {
                    if (solve(visited, grid, i, j, -1, -1, grid[i][j]))
                        return true;
                }
            }
        }
        return false;
    }
};
