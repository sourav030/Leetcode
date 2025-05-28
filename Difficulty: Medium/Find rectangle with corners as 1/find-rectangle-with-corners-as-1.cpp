class Solution {
  public:
    bool solve(int col1, int col2, vector<vector<int>>& mat, int row) {
        for (int i = row + 1; i < mat.size(); i++) {
            if (mat[i][col1] == 1 && mat[i][col2] == 1) {
                return true; // Found a rectangle
            }
        }
        return false;
    }

    bool ValidCorner(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();

        for (int i = 0; i < rows; i++) {
            for (int col1 = 0; col1 < cols; col1++) {
                if (mat[i][col1] != 1) continue;
                for (int col2 = col1 + 1; col2 < cols; col2++) {
                    if (mat[i][col2] == 1) {
                        if (solve(col1, col2, mat, i)) {
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }
};
