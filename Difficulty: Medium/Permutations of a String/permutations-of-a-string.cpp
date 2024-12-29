//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  void solve(set<string> &ans, string s, int index, int n){
      if(index==n){
          ans.insert(s);
          return;
      }
      for(int i=index; i<n; i++){
          swap(s[i],s[index]);
          solve(ans, s, index+1, n);
          swap(s[i],s[index]);
      }
  }
    vector<string> findPermutation(string &s) {
        // Code here there
        set<string>ans;
        solve(ans,s,0,s.size());
        vector<string>arr;
        for(auto a:ans){
            arr.push_back(a);
        }
        return arr;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        vector<string> ans = ob.findPermutation(S);
        sort(ans.begin(), ans.end());
        for (auto i : ans) {
            cout << i << " ";
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends