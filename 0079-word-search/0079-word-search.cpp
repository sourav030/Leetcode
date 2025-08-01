class Solution {
public:
    vector<int> row = {-1, 1, 0, 0};
    vector<int> col = {0, 0, 1, -1};
    int n, m;

    bool solve(vector<vector<char>>& matrix, int r, int c, string& word, int idx) {
        if (idx == word.length()) return true;

        char temp = matrix[r][c];
        matrix[r][c] = '#';  

        for (int i = 0; i < 4; i++) {
            int new_r = r + row[i];
            int new_c = c + col[i];

            if (new_r >= 0 && new_r < n && new_c >= 0 && new_c < m &&
                matrix[new_r][new_c] == word[idx]) {
                if (solve(matrix, new_r, new_c, word, idx + 1)) {
                    return true;
                }
            }
        }

        matrix[r][c] = temp;  
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0]) {
                    if (solve(board, i, j, word, 1)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
