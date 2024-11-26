//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // arr: input array
    // Function to find maximum circular subarray sum.
    


// Helper function to calculate the maximum subarray sum using Kadane's algorithm
int kadane(const vector<int>& arr) {
    int max_ending_here = 0, max_so_far = INT_MIN;
    for (int num : arr) {
        max_ending_here = max(num, max_ending_here + num);
        max_so_far = max(max_so_far, max_ending_here);
    }
    return max_so_far;
}

int circularSubarraySum(vector<int>& arr) {
    // Step 1: Find the max sum without wrapping
    int max_normal = kadane(arr);

    // If all elements are negative, return max_normal (maximum single element)
    if (max_normal < 0) {
        return max_normal;
    }

    // Step 2: Calculate total sum of the array
    int total_sum = 0;
    for (int num : arr) {
        total_sum += num;
    }

    // Step 3: Find the min sum subarray using Kadane's algorithm on inverted array
    vector<int> inverted_arr = arr;
    for (int& num : inverted_arr) {
        num = -num; // Invert the array
    }
    int min_sum = kadane(inverted_arr); // Min sum is -max_sum of inverted array

    // Step 4: Calculate the max sum with wrapping
    int max_circular = total_sum + min_sum; // Circular max = total_sum - min_sum

    // Step 5: Return the maximum of normal and circular subarray sums
    return max(max_normal, max_circular);
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

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.circularSubarraySum(arr);

        cout << res << endl;
    }
    return 0;
}

// } Driver Code Ends