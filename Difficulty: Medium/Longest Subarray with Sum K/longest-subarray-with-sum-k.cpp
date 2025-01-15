//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        int ans=0;
        unordered_map<int,int>mp;
        int sum=0;
        for(int i=0; i<arr.size(); i++){
            sum+=arr[i];
            if(sum==k){
                ans=max(ans,i-0+1);
            }
            
            if(mp.find(sum-k)!=mp.end()){
                ans=max(ans,i-mp[sum-k]);
            }
            
            if (mp.find(sum) == mp.end()) {
            mp[sum] = i;
        }
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