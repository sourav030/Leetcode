class Solution {
public:
    vector<vector<string>> result;
    int N;

    bool isValid(vector<string>& board, int row, int col) {
        for (int i = row - 1; i >= 0; i--) {
            if (board[i][col] == 'Q') return false;
        }

        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') return false;
        }

        for (int i = row - 1, j = col + 1; i >= 0 && j < N; i--, j++) {
            if (board[i][j] == 'Q') return false;
        }

        return true;
    }

    void solve(vector<string>& board, int row) {
        if (row >= N) {
            result.push_back(board);
            return;
        }
        for (int i = 0; i < N; i++) {
            if (isValid(board, row, i)) {
                board[row][i] = 'Q';
                solve(board, row + 1);
                board[row][i] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        this->N = n; // Fix applied here
        vector<string> board(n, string(n, '.'));
        solve(board, 0);
        return result;
    }
};
