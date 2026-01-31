class Solution {
public:
    bool solve(vector<vector<int>>& matrix, int target, int row){
        int end=matrix[0].size()-1;
        int start=0;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(matrix[row][mid]==target){
                return true;
            }
            else if(matrix[row][mid]<target){
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int i=0;
        int col=matrix[0].size()-1;
        while(i<n){
            int first=matrix[i][0];
            int end=  matrix[i][col];
            if(first<=target and target<=end){
                if(solve(matrix,target,i)){
                    return 1;
                }
            }
            i++;
        }
        return false;
    }
};