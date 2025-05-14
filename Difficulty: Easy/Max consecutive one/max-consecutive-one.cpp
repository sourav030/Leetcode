//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    int maxConsecutiveCount(vector<int> &arr) {
        // code here
        int ans=0;
        int one=0;
        int zero=0;
        for(int i=0; i<arr.size(); i++){
            if(arr[i]==1){
                one++;
                zero=0;
                ans=max(ans,one);
            }else{
                one=0;
                zero++;
                ans=max(ans,zero);
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int ans = ob.maxConsecutiveCount(arr);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends