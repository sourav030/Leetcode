class Solution {
public:
    void leftShift(vector<vector<int>>& mat, int row) {
        int n = mat[0].size();
        int first = mat[row][0];
        for (int i = 1; i < n; i++) {
            mat[row][i - 1] = mat[row][i];
        }
        mat[row][n - 1] = first;
    }

    void rightShift(vector<vector<int>>& mat, int row) {
        int n = mat[0].size();
        int last = mat[row][n - 1];
        for (int i = n - 1; i > 0; i--) {
            mat[row][i] = mat[row][i - 1];
        }
        mat[row][0] = last;
    }

    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> arr(n, vector<int>(m));
        
      
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                arr[i][j] = mat[i][j];
            }
        }

      
        int steps = k % m;
        for (int i = 0; i < n; i++) {
            for (int s = 0; s < steps; s++) {
                if (i % 2 == 0) {
                    leftShift(arr, i);
                } else {
                    rightShift(arr, i);
                }
            }
        }

        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] != arr[i][j]) {
                    return false;
                }
            }
        }

        return true;
    }
};
