//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
   int lenOfLongestSubarr(vector<int>& arr, int k) {
    int prefixSum = 0; // Prefix Sum Tracker
    int len = 0;       // Length of Longest Subarray
    map<int, int> mp;  // HashMap to store prefixSum and its first occurrence index

    for (int i = 0; i < arr.size(); i++) {
        prefixSum += arr[i]; // Calculate prefix sum

        // If prefixSum is equal to k, update length to i + 1
        if (prefixSum == k) {
            len = max(len, i + 1);
        }

        
        int rem = prefixSum - k;
        if (mp.find(rem) != mp.end()) {
            int currLen = i - mp[rem]; // Length of subarray
            len = max(len, currLen);  // Update max length
        }

        // Store the prefixSum in the map if not already present
        if (mp.find(prefixSum) == mp.end()) {
            mp[prefixSum] = i;
        }
    }

    return len;
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
        cout << solution.lenOfLongestSubarr(arr, k) << "\n";
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends