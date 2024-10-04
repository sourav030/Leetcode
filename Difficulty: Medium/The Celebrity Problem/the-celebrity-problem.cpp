//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat) {
        // code here
        stack<int>st;
        int n=mat.size();
        for(int i=n-1; i>=0;i--){
            st.push(i);
        }
        
        int first;
        int second;
        while(st.size()>1){
            
            first=st.top();
            st.pop();
            second=st.top();
            st.pop();
            
            if(mat[first][second]==1 and mat[second][first]==0){
                st.push(second);
            }
            else if (mat[first][second]==0 and mat[second][first]==1)
            {
                st.push(first);
            }
        }
        
        if(st.empty()){
            return -1;
        }
        int row=0;
        int col=0;
        int num=st.top();
        
        for(int i=0; i<n; i++){
            row+=mat[num][i];
             col+=mat[i][num];
        }
      
        return row==0 and col==n-1? num: -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int> > M(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> M[i][j];
            }
        }
        Solution ob;
        cout << ob.celebrity(M) << endl;
    }
}

// } Driver Code Ends