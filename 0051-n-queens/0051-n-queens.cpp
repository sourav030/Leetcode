class Solution {
public:
    bool isSafe(int row, int col, vector<vector<string>>& board, int n) {
        // Check column
        for (int i = row; i >= 0; i--) {
            if (board[i][col] == "Q") return false;
        }
        // Check left diagonal
        int i = row, j = col;
        while (i >= 0 && j >= 0) {
            if (board[i][j] == "Q") return false;
            i--; j--;
        }
        // Check right diagonal
        i = row, j = col;
        while (i >= 0 && j < n) {
            if (board[i][j] == "Q") return false;
            i--; j++;
        }
        return true;
    }

    void solve(int row, vector<vector<string>>& board, int n, vector<vector<string>>& ans) {
        if (row == n) {
            vector<string> temp;
            for (auto it : board) {
                string rowStr = "";
                for (auto cell : it) rowStr += cell;
                temp.push_back(rowStr);
            }
            ans.push_back(temp);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (isSafe(row, i, board, n)) {
                board[row][i] = "Q";
                solve(row + 1, board, n, ans);
                board[row][i] = ".";
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<vector<string>> board(n, vector<string>(n, "."));
        solve(0, board, n, ans);
        return ans;
    }
};
