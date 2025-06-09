class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
       if(m*n!=original.size()){
          vector<vector<int>>arr;
          return arr;
       } 
       vector<vector<int>>arr(m,vector<int>(n,0));
       int row=0;
       for(int i=0; i<original.size(); i++){
            int a=i%n;
            arr[row][a]=original[i];
            if((i+1)%n==0){
                row++;
            }
       }
       return arr;
    }
};