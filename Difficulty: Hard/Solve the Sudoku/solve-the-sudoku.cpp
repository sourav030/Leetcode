//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find a solved Sudoku.
    bool satify(vector<vector<int>> &mat,int i, int j, int num){
        for(int r=0; r<9; r++){
            if(mat[i][r]==num || mat[r][j]==num) return false;
        }
        int sr=i-i%3;
        int sc=j-j%3;
        
        for(int r=0; r<3; r++){
            for(int c=0; c<3; c++){
                if(mat[sr+r][sc+c]==num) return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<int>> &mat){
        
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(mat[i][j]==0){
                    for(int num=1; num<=9; num++){
                        if(satify(mat,i,j,num)){
                            mat[i][j]=num;
                            if(solve(mat)) return true;
                            mat[i][j]=0;
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    void solveSudoku(vector<vector<int>> &mat) {
        // code here
        solve(mat);
    }
};

//{ Driver Code Starts.

vector<int> inputLine() {
    string str;
    getline(cin, str);
    stringstream ss(str);
    int num;
    vector<int> res;
    while (ss >> num) {
        res.push_back(num);
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<vector<int>> grid;
        for (int i = 0; i < 9; i++) {
            vector<int> v = inputLine();
            grid.push_back(v);
        }

        Solution ob;

        ob.solveSudoku(grid);

        for (auto v : grid) {
            for (auto elem : v) {
                cout << elem << " ";
            }
            cout << endl;
        }

        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends