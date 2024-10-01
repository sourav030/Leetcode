//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> makeBeautiful(vector<int> arr) {
        stack<int> s;

      
        for(int i = 0; i < arr.size(); i++) {
          
            if(s.empty()) {
                s.push(arr[i]);
            }
            else {
               
                int topElement = s.top();
                
               
                if((topElement >= 0 && arr[i] < 0) || (topElement < 0 && arr[i] >= 0)) {
                    s.pop();
                }
               
                else {
                    s.push(arr[i]);
                }
            }
        }

       
        vector<int> ans;
        while(!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }

     
        reverse(ans.begin(), ans.end());
        return ans;
    }

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        Solution obj;
        vector<int> res = obj.makeBeautiful(arr);
        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }

        cout << "\n";
    }
}
// } Driver Code Ends