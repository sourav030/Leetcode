//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
   vector<int> sumClosest(vector<int>& arr, int target) {
    int n = arr.size();
    if (n < 2) return {}; // If there are fewer than 2 elements, no pair exists
    
    sort(arr.begin(), arr.end());
    
    int left = 0, right = n - 1;
    int closestSum = INT_MAX;
    vector<int> result;
    
    while (left < right) {
        int currentSum = arr[left] + arr[right];
        
        // Check if the current pair is closer to the target
        if (abs(currentSum - target) < abs(closestSum - target)) {
            closestSum = currentSum;
            result = {arr[left], arr[right]};
        }
        // If current sum is equally close, check for maximum absolute difference
        else if (abs(currentSum - target) == abs(closestSum - target)) {
            if (abs(arr[left] - arr[right]) > abs(result[0] - result[1])) {
                result = {arr[left], arr[right]};
            }
        }
        
        // Adjust pointers
        if (currentSum < target) {
            left++;
        } else {
            right--;
        }
    }
    
    return result;
}
};

//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int target = stoi(ks);
        Solution ob;
        vector<int> ans = ob.sumClosest(arr, target);
        if (ans.empty()) {
            cout << "[]";
        } else {
            for (auto it : ans) {
                cout << it << " ";
            }
        }
        cout << endl;
        cout << "~\n";
    }

    return 0;
}
// } Driver Code Ends