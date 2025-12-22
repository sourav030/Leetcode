class Solution {
public:
    void RowZero(vector<vector<int>>& matrix, int idx){
        int n=matrix[0].size();
        for(int i=0; i<n; i++){
            matrix[idx][i]=0;
        }
    }
    void ColZero(vector<vector<int>>& matrix, int idx){
        int n=matrix.size();
        for(int i=0; i<n; i++){
            matrix[i][idx]=0;
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int>row;
        vector<int>col;
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                if(matrix[i][j]==0){
                    row.push_back(i);
                    col.push_back(j);
                }
            }
        }
        for(int i=0; i<row.size(); i++){
            RowZero(matrix,row[i]);
        }
        for(int i=0; i<col.size(); i++){
            ColZero(matrix,col[i]);
        }
    }
};