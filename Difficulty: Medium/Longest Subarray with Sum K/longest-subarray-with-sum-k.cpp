//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        int sum=0;
        int ans=0;
        unordered_map<int,int>mp;
        int n=arr.size();
        int start=0;
        while(start<n){
           sum+=arr[start];
           if(sum==k){
               ans=max(ans,start-0+1);
           }
           if(mp.find(sum-k)!=mp.end()){
               ans=max(ans,start-mp[sum-k]);
           }
           if(mp.find(sum)==mp.end()){
               mp[sum]=start;
           }
           start++;
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int k;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> k;
        cin.ignore(); // Ignore newline character after k input

        Solution solution;
        cout << solution.longestSubarray(arr, k) << "\n";
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends