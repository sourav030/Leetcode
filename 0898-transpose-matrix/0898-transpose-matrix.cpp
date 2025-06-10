class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>result(m,vector<int>(n,0));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                result[i][j]=matrix[j][i];
            }
        }
        return result;
    }
};