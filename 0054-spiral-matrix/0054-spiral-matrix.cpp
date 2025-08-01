class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rowStart = 0;
        int colStart = 0;
        int rowEnd = matrix.size() - 1;
        int colEnd = matrix[0].size() - 1;
        int total = (rowEnd + 1) * (colEnd + 1);
        int count = 0;
        vector<int> ans;

        while (count < total && rowStart <= rowEnd && colStart <= colEnd) {

            for (int i = colStart; (i <= colEnd) && (count < total); i++) {
                ans.push_back(matrix[rowStart][i]);
                count++;
            }
            rowStart++;

            for (int i = rowStart; (i <= rowEnd) && (count < total); i++) {
                ans.push_back(matrix[i][colEnd]);
                count++;
            }
            colEnd--;

            for (int i = colEnd; (i >= colStart) && (count < total); i--) {
                ans.push_back(matrix[rowEnd][i]);
                count++;
            }
            rowEnd--;

            for (int i = rowEnd; (i >= rowStart) && (count < total); i--) {
                ans.push_back(matrix[i][colStart]);
                count++;
            }
            colStart++;
        }

        return ans;
    }
};
