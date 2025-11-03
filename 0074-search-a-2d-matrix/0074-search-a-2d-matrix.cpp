class Solution {
public:
    bool solve(vector<vector<int>>&matrix,int row,int target){
        int low=0;
        int end=matrix[0].size()-1;
        while(low<=end){
            int mid=low+(end-low)/2;
            if(matrix[row][mid]==target){
                return true;
            }
            else if(matrix[row][mid]>target){
                end=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low=0;
        int end=matrix.size()-1;
        int n=matrix[0].size()-1;
        while(low<=end){
            int mid=low+(end-low)/2;
            if(matrix[mid][0]<=target and matrix[mid][n]>=target){
                if(solve(matrix,mid,target)){
                    return true;
                }
                else 
                  return false;
            }
            else if(matrix[mid][0]>target){
                end=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return false;
    }
};