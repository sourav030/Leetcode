class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        if(matrix.empty()) return {};

        int m = matrix.size(), n = matrix[0].size();
        vector<int> result;
        result.reserve(m * n);

        int r = 0, c = 0, dir = 1; // start from top-left, going up-right

        while(result.size() < m * n) {
            result.push_back(matrix[r][c]);

            // moving up-right
            if(dir == 1) {
                if(c == n - 1) { r++; dir = -1; }
                else if(r == 0) { c++; dir = -1; }
                else { r--; c++; }
            }
            // moving down-left
            else {
                if(r == m - 1) { c++; dir = 1; }
                else if(c == 0) { r++; dir = 1; }
                else { r++; c--; }
            }
        }
        return result;
    }
};
