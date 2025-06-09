class Solution {
public:
    int check(vector<vector<int>>&matrix, int col){
         int ans=INT_MIN;
         for(int i=0; i<matrix.size(); i++){
            ans=max(ans,matrix[i][col]);
         }
         return ans;
    }
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                if(matrix[i][j]==-1){
                   int ans= check(matrix,j);
                   matrix[i][j]=ans;
                }
            }
        }
        return matrix;
    }
};