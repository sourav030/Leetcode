
class Solution {
public:
    vector<vector<int>> arr;
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};

    bool check(vector<vector<char>>& board, int idx, int idy,
               string &word, int i) {

        if (i == word.length()) {
            return true;
        }

        if (idx < 0 || idx >= board.size() ||
            idy < 0 || idy >= board[0].size()) {
            return false;
        }

        if (board[idx][idy] != word[i] || arr[idx][idy]) {
            return false;
        }

        arr[idx][idy] = 1;

        for (int d = 0; d < 4; d++) {
            int new_r = idx + dx[d];
            int new_c = idy + dy[d];

            if (check(board, new_r, new_c, word, i + 1)) {
                return true;
            }
        }

        arr[idx][idy] = 0; 
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty() || board[0].empty()) {
            return false;
        }

        int n = board.size();
        int m = board[0].size();

        arr.assign(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (check(board, i, j, word, 0)) {
                    return true;
                }
            }
        }

        return false;
    }
};
