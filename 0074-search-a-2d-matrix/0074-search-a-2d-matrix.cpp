class Solution {
    bool solve(vector<int>arr, int n, int target){
        int low=0;
        int high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid]==target){
                return true;
            }
            else if (arr[mid]<target){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return false;
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size();
        int col=matrix[0].size();
        int low=0;
        int high=row-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(matrix[mid][0]<=target and target<=matrix[mid][col-1]){
                return solve(matrix[mid],col, target);
            }
            else if (target>matrix[mid][0] and target>matrix[mid][col-1]){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return 0;
    }
};