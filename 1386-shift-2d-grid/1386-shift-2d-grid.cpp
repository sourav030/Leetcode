class Solution {
public:
    void solve(vector<int>&arr){
        int n=arr.size()-1;
        int ele=arr[n];
        for(int i=n-1; i>=0; i--){
            arr[i+1]=arr[i];
        }
        arr[0]=ele;
    }
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        vector<int>arr;
        for(int i=0; i<grid.size(); i++){
            for(int j=0;j<grid[0].size(); j++){
                arr.push_back(grid[i][j]);
            }
        }
        while(k--){
            solve(arr);
        }
        int idx=0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                grid[i][j]=arr[idx];
                idx++;
            }
        }
        return grid;
    }
};