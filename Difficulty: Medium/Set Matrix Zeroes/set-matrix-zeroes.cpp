//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
    void setRowZero(vector<vector<int>> &mat, int row, int n)
    {
        for(int i=0; i<n; i++){
            mat[row][i]=0;
        }
    }
    void setColZero(vector<vector<int>> &mat, int col, int n){
        for(int i=0; i<n; i++){
            mat[i][col]=0;
        }
    }
  public:
    void setMatrixZeroes(vector<vector<int>> &mat) {
        // code here
        vector<int>row;
        vector<int>col;
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j]==0){
                    row.push_back(i);
                    col.push_back(j);
                }
            }
        }
        
        // set row zero
        for(int i=0; i<row.size(); i++){
            setRowZero(mat,row[i],m);
        }
        // set col zero
        for(int i=0; i<col.size(); i++){
            setColZero(mat,col[i],n);
        }
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int> > arr(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> arr[i][j];
            }
        }
        Solution ob;
        ob.setMatrixZeroes(arr);
        for (auto x : arr) {
            for (auto y : x)
                cout << y << " ";
            cout << endl;
        }

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends