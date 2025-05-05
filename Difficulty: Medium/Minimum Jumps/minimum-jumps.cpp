//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// Function to return minimum number of jumps to end of array

class Solution {
  public:
int minJumpsHelper(vector<int>& arr, int index, int n, vector<int>& memo) {
    // Base Cases:
    if (index >= n - 1) return 0; // Already at or beyond the last index
    if (arr[index] == 0) return -1; // Cannot move forward
    if (memo[index] != -1) return memo[index]; // Return cached result

    int minJumps = INT_MAX;

    // Try every step size from 1 to arr[index]
    for (int step = 1; step <= arr[index]; step++) {
        int result = minJumpsHelper(arr, index + step, n, memo);
        if (result != -1) {
            minJumps = min(minJumps, result + 1);
        }
    }

    // Store the result for this index in the memo table
    memo[index] = (minJumps == INT_MAX) ? -1 : minJumps;
    return memo[index];
}

int minJumps(vector<int>& arr) {
    int n = arr.size();
    vector<int> memo(n, -1); // Memoization array initialized with -1
    return minJumpsHelper(arr, 0, n, memo);
}

};




//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, i, j;
        vector<int> arr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.minJumps(arr) << endl << "~\n";
    }
    return 0;
}

// } Driver Code Ends