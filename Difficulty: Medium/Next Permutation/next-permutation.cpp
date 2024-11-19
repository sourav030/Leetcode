//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void nextPermutation(vector<int>& nums) {
        // code here
         int n = nums.size(), i, j;
    
    // Step 1: Find the first decreasing element
    for (i = n - 2; i >= 0; i--) {
        if (nums[i] < nums[i + 1]) break;
    }

    if (i >= 0) { // If a decreasing element exists
        // Step 2: Find the element just larger than nums[i]
        for (j = n - 1; j > i; j--) {
            if (nums[j] > nums[i]) break;
        }
        // Step 3: Swap nums[i] and nums[j]
        swap(nums[i], nums[j]);
    }

    // Step 4: Reverse the elements from i+1 to end
    reverse(nums.begin() + i + 1, nums.end());
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
        int n = arr.size();
        ob.nextPermutation(arr);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends