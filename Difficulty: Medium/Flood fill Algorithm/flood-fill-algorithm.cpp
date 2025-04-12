//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int n;
    int m;
    bool isValid(int row, int col){
        if(row>=0 and row<n and col>=0 and col<m){
            return true;
        }
        else{
            return false;
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int newColor) {
        // Code here
         n=image.size();
         m=image[0].size();
        int oldColor=image[sr][sc];
         if (oldColor == newColor) return image;
        queue<pair<int,int>>q;
        q.push({sr,sc});
        vector<int>row={-1,1,0,0};
        vector<int>col={0,0,1,-1};
        image[sr][sc]=newColor;
        
        while(!q.empty()){
            int new_r=q.front().first;
            int new_c=q.front().second;
            q.pop();
            for(int i=0; i<4; i++){
                int new_row=new_r+row[i];
                int new_col=new_c+col[i];
                if(isValid(new_row,new_col) and image[new_row][new_col]==oldColor){
                    image[new_row][new_col]=newColor;
                    q.push({new_row,new_col});
                }
            }
        }
        
        return image;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> image(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cin >> image[i][j];
        }
        int sr, sc, newColor;
        cin >> sr >> sc >> newColor;
        Solution obj;
        vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
        for (auto i : ans) {
            for (auto j : i)
                cout << j << " ";
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends