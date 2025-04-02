//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int orangesRotting(vector<vector<int>>& mat) {
        // Code here
        int n=mat.size();
        int m=mat[0].size();
        queue<pair<int,pair<int,int>>>q;
        int rotten=0;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j]==2){
                    
                    q.push({0,{i,j}});
                }
                else if (mat[i][j]==1) rotten++;
            }
        }
        int r[]={0,0,-1,1};
        int c[]={1,-1,0,0};
        int ans=0;
        while(!q.empty()){
            auto node=q.front();
            int time=node.first;
            int row=node.second.first;
            int col=node.second.second;
            
            ans=max(ans,time);
            q.pop();
            for(int i=0; i<4; i++){
                int new_r=row+r[i];
                int new_c=col+c[i];
                if(new_r>=0 and new_r<n and new_c>=0 and new_c<m){
                  if ( mat[new_r][new_c]==1){
                      rotten--;
                      q.push({time+1,{new_r,new_c}});
                      mat[new_r][new_c]=2;
                     
                  }
                }
            }
            
        }
        if(rotten!=0) return -1;
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> mat[i][j];
            }
        }
        Solution obj;
        int ans = obj.orangesRotting(mat);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends