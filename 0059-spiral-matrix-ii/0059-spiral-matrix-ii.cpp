class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> mat(n, vector<int>(n, 0));
        
        int left = 0, right = n - 1;
        int top = 0, bottom = n - 1;
        int val = 1;
        
        while (left <= right && top <= bottom) {
            // Fill top row
            for (int i = left; i <= right; i++) {
                mat[top][i] = val++;
            }
            top++;

            // Fill right column
            for (int i = top; i <= bottom; i++) {
                mat[i][right] = val++;
            }
            right--;

            // Fill bottom row
            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    mat[bottom][i] = val++;
                }
                bottom--;
            }

            // Fill left column
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    mat[i][left] = val++;
                }
                left++;
            }
        }

        return mat;
    }
};
