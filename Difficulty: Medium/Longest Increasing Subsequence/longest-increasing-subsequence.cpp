//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    // Function to find length of longest increasing subsequence.
    int longestSubsequence(vector<int>& arr) {
        // code here
        unordered_set<int> s(arr.begin(), arr.end());
vector<int> arr2(s.begin(), s.end());
sort(arr2.begin(), arr2.end());

int n = arr.size();
int m = arr2.size();

vector<int> prev(m + 1, 0), curr(m + 1, 0);

for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
        if (arr[i - 1] == arr2[j - 1]) {
            curr[j] = 1 + prev[j - 1];
        } else {
            curr[j] = max(prev[j], curr[j - 1]);
        }
    }
    prev = curr;  // Move to the next row
}

return prev[m];

    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input

    while (t--) {
        int n;
        vector<int> arr;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            arr.push_back(num);

        Solution obj;
        cout << obj.longestSubsequence(arr) << endl;
    }

    return 0;
}

// } Driver Code Ends